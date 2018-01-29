// drainerbolt.c

#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
	string msg;
	int damage, ap, dp;

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	target->is_corpse()
	||	target==me)
		return notify_fail("你要對誰施展這個法術？\n");

	if((int)me->query("mana") < 25 )
		return notify_fail("你的法力不夠！\n");

	if((int)me->query("sen") < 20 )
		return notify_fail("你的精神沒有辦法有效集中！\n");

	me->add("mana", -25);
	me->receive_damage("sen", 20);

	if( random(me->query("max_mana")) < 50 ) {
		write("你失敗了。\n");
		return 1;
	}

	msg = HIM "$N口中喃喃地念著咒文，左手一揮，手中聚起一團紫光射向$n！\n\n" NOR;

	ap = me->query_skill("spells");
	ap = ( ap * ap * ap / 4 ) * (int)me->query("sen") / 100;
	dp = target->query("combat_exp");
	if( random(ap + dp) > dp ) {
		damage = (int)me->query("max_mana") / 20 + random((int)me->query("eff_sen") / 10);
		damage -= (int)target->query("max_mana") / 30 + random((int)me->query("eff_sen") / 15);
		if( damage > 0 ) {
			msg +=  HIR "結果「嗤」地一聲，紫光從$p身上透體而過，拖出一條長長的七彩光氣，光氣繞了\n"
					"迴轉過來又從$N頂門注入$P的體內！\n" NOR;
			me->receive_heal("gin", target->receive_damage("gin", damage, me));
			target->receive_wound("gin", damage/3, me);
			me->improve_skill("necromancy", 1, 1);
		} else
			msg += "結果「嗤」地一聲，紫光從$p身上透體而過，無聲無息地鑽入地下！\n";
	} else
		msg += "但是被$n躲開了。\n";

	message_vision(msg, me, target);
	if( damage > 0 ) COMBAT_D->report_status(target);

	if( !target->is_fighting(me) ) {
		if( living(target) ) {
			if( userp(target) ) target->fight_ob(me);
			else 				target->kill_ob(me);
		}
		me->kill_ob(target);
	}

	me->start_busy(2);
	return 1;
}

