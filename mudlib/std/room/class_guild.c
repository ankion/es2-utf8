// guild.c

inherit ROOM;

void setup()
{
	::setup();
}

void init()
{
	add_action("do_join", "join");
}

int do_join(string arg)
{
	object me;

	me = this_player();
	if( stringp(me->query("class")) )
		return notify_fail("你已經參加了其他公會。\n");
	me->set("class", "fighter");
	me->set("startroom", CLASS_D("fighter") + "/guildhall");
	write("\n恭喜，從今天起您已經成爲一名武者！\n\n");
	return 1;
}

