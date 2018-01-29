//saveme.c 

inherit SSERVER;

int cast(object me, object target)
{
	object soldier;

	if( !me->is_fighting() )
		return notify_fail("只有戰鬥中才能召喚天將！\n");
	
	if( (int)me->query("mana") < 100 )
		return notify_fail("你的法力不夠了！\n");

	if( (int)me->query("sen") < 60 )
		return notify_fail("你的精神無法集中！\n");

	message_vision("$N喃喃地念了幾句咒語。\n", me);

	me->add("mana", -100);
	me->receive_damage("sen", 60);

	if( random(me->query_skill("spells")) < 60 ) {
		message("vision", "但是什麼也沒有發生。\n", environment(me));
		return 1;
	}

	seteuid(getuid());
	soldier = new("/obj/npc/heaven_soldier");
	soldier->move(environment(me));
	soldier->invocation(me);

	return 1;
}
