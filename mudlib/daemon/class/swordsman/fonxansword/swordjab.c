// swordjab.c

#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
	string msg;
	int i;

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("「逐」字訣只能對戰鬥中的對手使用。\n");

	msg = CYN "$N使出封山劍法「逐」字訣，劍法一緊，劍光罩向$n，";

	if( random(me->query("combat_exp")) > (int)target->query("combat_exp")*2/3 ) {
		msg += "$p已顯吃力。\n" NOR;
		for (i=0; i<random (3)+1; i++)
			COMBAT_D->do_attack(me, target, me->query("weapon"));
		} 
	    else {
		msg += "$p從容化解\n" NOR;
		}
	message_vision(msg, me, target);

	me->add("eff_kee",  -10);

	return 1;
}
