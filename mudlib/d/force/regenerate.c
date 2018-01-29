// regenerate.c

inherit SSERVER;

int exert(object me, object target)
{
	int heal, heal1, heal2, cost=20;

	if( target != me ) return notify_fail("你只能用內功\恢復自己的精力。\n");

	if( (int)me->query("force") < 20 ) return notify_fail("你的內力不夠。\n");

	heal1 = (int)me->query("eff_gin") - (int)me->query("gin");

	if( heal1 < 1 ) return notify_fail("你的精力已經恢復到上限了。\n");

//	if( (int)me->query_skill("force") < 1 ) return notify_fail("你失敗了。\n");
//	cost = heal * 10 / ((int)me->query_skill("force")/5+1);

	heal2 = (int)me->query_skill("force")/3 + 10;
	heal = (heal1 - heal2) ? heal2 : heal1;

//	if( (int)me->query("force") < cost ) {
//		heal = heal * (int)me->query("force") / cost;
//		me->set("force", 0);
//		me->receive_heal("gin", heal);
//	} else {
		me->add("force", - cost);
		me->receive_heal("gin", heal);
//	}

	message_vision("$N深深地吸了口氣，手腳活動了幾下，看起來有活力多了。\n", me);

	if( me->is_fighting() ) me->start_busy(1);

	return 1;
}
