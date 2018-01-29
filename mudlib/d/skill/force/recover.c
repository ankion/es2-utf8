// recover.c

int exert(object me, object target)
{
	if( target ) return notify_fail("你只能用內功\調勻自己的氣息。\n");

	if( (int)me->query("force") < 20 )
		return notify_fail("你的內力不夠。\n");

	me->receive_heal("kee", 10 + (int)me->query_skill("force")/3 );
	me->add("force", -20);

	message_vision("$N深深吸了幾口氣，臉色看起來好多了。\n", me);

	if( me->is_fighting() ) me->start_busy(1);

	return 1;
}
