// dun.c

#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
        string msg;
        int busy_time, ap, dp;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse() )
                return notify_fail("你要對誰施展這個法術？\n");

	if ( !me->is_fighting() )
		return notify_fail("這個法術只能在戰鬥中使用！\n");
	
	if ( target == me ) {
	        if((int)me->query("mana") < 80 )
        	        return notify_fail("你的法力不夠！\n");
	        if((int)me->query("sen") < 30 )
        	        return notify_fail("你的精神沒有辦法有效集中！\n");
	        me->add("mana", -80);
	        me->receive_damage("sen", 30);
	
	        if( random(me->query_skill("spells")) < 30 ) {
	                write("你失敗了。\n");
	                return 1;
	        }
		switch ( random(5) ) {
		case 0:
	        msg = HIW "$N口中喃喃地念著咒文，忽然大喝一聲“疾！”\n"  +
		"只見$N化作一道黑氣，然後消失得無影無蹤！\n\n"NOR ;
		break ;
		case 1:
	        msg = HIW "$N口中喃喃地念著咒文，忽然大喝一聲“疾！”\n"  +
		"只見$N化作一道金光，然後消失得無影無蹤！\n\n"NOR ;
		break ;
		case 2:
	        msg = HIW "$N口中喃喃地念著咒文，忽然大喝一聲“疾！”\n"  +
		"只見$N化作一團火焰，然後消失得無影無蹤！\n\n"NOR ;
		break ;
		case 3:
	        msg = HIW "$N口中喃喃地念著咒文，忽然大喝一聲“疾！”\n"  +
		"只見$N化作一道長虹，然後消失得無影無蹤！\n\n"NOR ;
		break ;
		case 4:
	        msg = HIW "$N口中喃喃地念著咒文，忽然大喝一聲“疾！”\n"  +
		"只見$N化作一團大霧，然後消失得無影無蹤！\n\n"NOR ;
		break ;
		}
	        message_vision(msg, me);
		me->move("/d/snow/temple");
		return 1 ;
	}
	if ( target->is_busy() ) {
                return notify_fail(target->name()+"正自顧不暇，放膽進攻吧。\n");
        }
             	
        if((int)me->query("mana") < 200 )
                return notify_fail("你的法力不夠！\n");
        if((int)me->query("sen") < 80 )
                return notify_fail("你的精神沒有辦法有效集中！\n");

        me->add("mana", -200);
        me->receive_damage("sen", 80);

        if( random(me->query_skill("spells")) < 40 ) {
                write("你失敗了。\n");
                return 1;
        }
        switch ( random(5) ) {
	case 0:    
        msg = HIW "$N口中喃喃地念著咒文，忽然大喝一聲“疾！”\n"  +
	"只見一道黑氣罩在$n身上！\n\n"NOR ;
	break ;
	case 1:
        msg = HIW "$N口中喃喃地念著咒文，忽然大喝一聲“疾！”\n"  +
	"只見一道金光罩在$n身上！\n\n"NOR ;
	break;
	case 2:
        msg = HIW "$N口中喃喃地念著咒文，忽然大喝一聲“疾！”\n"  +
	"只見一團火焰罩在$n身上！\n\n"NOR ;
	break;
	case 3:
        msg = HIW "$N口中喃喃地念著咒文，忽然大喝一聲“疾！”\n"  +
	"只聽在一聲海嘯，海水將$n團團圍住！\n\n"NOR ;
	break;
	case 4:
        msg = HIW "$N口中喃喃地念著咒文，忽然大喝一聲“疾！”\n"  +
	"只見空中落下無數大木，正把$n困在中央！\n\n"NOR ;
	break;
	}
        ap = me->query_skill("spells");
        ap = ( ap * ap * ap / 10 ) * (int)me->query("sen") / 100;
        dp = target->query("combat_exp");
        if( random(ap + dp) > dp ) {
		busy_time  = me->query("mana")/200;
		busy_time += busy_time * me->query("mana_facter") / 50 ;
		busy_time -= target->query("max_mana")/100;
		if ( busy_time < 0 ) busy_time = 0 ;
		target->start_busy(busy_time+2);
        } else {
                msg += "但是$n縱身一躍，脫離了圍困。\n";
		me->start_busy(1);
	}
        message_vision(msg, me, target);
        return 1;
}

