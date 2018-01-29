// Room: /d/oldpine/stone.c

inherit ROOM;

void create()
{
	set("short", "大青石上");
	set("long", @LONG
你現在正站在一塊突出的大青石上, 雖然有點滑, 你還是能站穩,
往四周看, 除了長滿了青苔的石壁, 好象無路可走了。
LONG
	);

	set("objects", ([
		__DIR__"npc/venomsnake":	1,
	]) );

	setup();
}

void init ()
{
	add_action ("do_climb", "climb");
}

int do_climb(string arg)
{
	if (!arg || arg != "down")
		return notify_fail ("想爬下去(down)嗎？\n");

	message_vision ("$N迅速地爬下大青石。\n",this_player());
	this_player()->move(__DIR__"cave1");
	return 1;
}

