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
	} else if( duration > limit/2 ) {
		tell_object(me, "你覺得腦中昏昏沉沉，心中空蕩蕩的，直想躺下來睡一覺。\n");
		message("vision", me->name() + "搖頭晃腦地站都站不穩，顯然是蒙汗藥的藥力發作了。\n",
			environment(me), me);
	}

	me->apply_condition("slumber_drug", duration - 1);
	if( !duration ) return 0;
	return 1;
}
