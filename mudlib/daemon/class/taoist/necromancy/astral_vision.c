// astral_vision.c

#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
	int skill;

	if( me->query_temp("apply/astral_vision") )
		return notify_fail("你已經施展過陰陽眼的法術了。\n");

	if( (int)me->query("mana") < 30 )
		return notify_fail("你的法力不夠。\n");

	skill = me->query_skill("spells");

	me->add("mana", - 30);
	me->receive_damage("sen", 5);

	message_vision(
		HIB "$N微一凝神，閉著眼睛唸了幾句咒語，施展「陰陽眼」法術。\n" NOR, me);

	me->add_temp("apply/astral_vision", 1);
	me->start_call_out( (: call_other, __FILE__, "remove_effect", me :), skill);

	if( me->is_fighting() ) me->start_busy(3);

	return 1;
}

void remove_effect(object me)
{
	me->add_temp("apply/astral_vision", -1);
	tell_object(me, "你的陰陽眼法術失效了。\n");
}
