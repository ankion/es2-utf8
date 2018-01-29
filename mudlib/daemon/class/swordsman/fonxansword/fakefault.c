#include <ansi.h>

inherit SSERVER;

void remove_effect(object me, object target, int amount)
{
	if ( living(target) && (environment(me) == environment(target)) ){
        	message_vision(CYN"$N突然對$n發出奮力一擊！\n"NOR, me, target);
        	me->add_temp("apply/attack", amount * 3 + (12-amount) * 10 );
                me->add_temp("apply/damage",(12-amount)*3) ;
        	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        	COMBAT_D->do_attack(target, me ,target->query_temp("weapon"));

        	me->add_temp("apply/attack",  -(12-amount) * 10 );
                me->add_temp("apply/damage", -(12-amount)*3);
	}
	else 
		me->add_temp("apply/attack",amount*3);
        me->add_temp("apply/dodge", - (12-amount) * 5 );
        me->delete_temp("fonxansword");
}

int perform (object me, object target)
{
        string msg;
        int skill;

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("'缺'字訣只能在戰鬥中使用。\n");
	if ( !living(target) || environment(me) != environment(target) )
		return notify_fail("你要對誰使用'缺'字訣？\n");
	if ( me->query_temp("fonxansword") )
		return notify_fail("你已經在運用中了。\n");
        msg  = CYN "$N劍招陡變，空門大開，誘使$n進招，\n";

        if (random(me->query("combat_exp")) > target->query("combat_exp")/2 ) {
//                msg += "\n$N看見機會，立刻放手進攻.\n" NOR;

                skill = (300 -(int) me->query_skill("sword")) /20;
		if ( skill > 10 ) skill = 10 ;
		if ( skill < 2 )  skill = 2 ;

                me->add_temp("apply/attack", -skill*3);
                me->add_temp("apply/dodge", (12-skill)*5);
                message_vision(msg, me, target);
		me->set("fonxansword",1);
	        me->start_call_out( (: call_other, __FILE__, "remove_effect", me,target,
skill :), skill);
                return 1;
                }

        msg += "\n可是$n看破了$N的企圖，並沒有上當。\n" NOR;
        message_vision(msg, me, target);
	me->start_busy(1);
        return 1;
}

 
