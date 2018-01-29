// drunk.c

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	int limit;

	limit = (me->query("con") + (int)me->query("max_force") / 50) * 2;

	if( duration > limit
	&&	living(me) ) {
		me->unconcious();
		return 0;
	} else if( !living(me) ) {
		message("vision", me->name() + "打了個隔，不過依然爛醉如泥。\n",
			environment(me), me);
	} else if( duration > limit/2 ) {
		tell_object(me, "你覺得腦中昏昏沉沉，身子輕飄飄地，大概是醉了。\n");
		message("vision", me->name() + "搖頭晃腦地站都站不穩，顯然是喝醉了。\n",
			environment(me), me);
		me->receive_damage("sen", 10);
	} else if( duration > limit/4 ) {
		tell_object(me, "你覺得一陣酒意上衝，眼皮有些沉重了。\n");
		message("vision", me->name() + "臉上已經略顯酒意了。\n",
			environment(me), me);
		me->receive_damage("sen", 3);
		me->receive_healing("gin", 10);
		me->receive_healing("kee", 15);
	}

	me->apply_condition("drunk", duration - 1);
	if( !duration ) return 0;
	return 1;
}
