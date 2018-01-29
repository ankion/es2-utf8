// Room: /d/oldpine/cliff2.c

inherit ROOM;

void create()
{
	set("short", "山壁上的窄穴");
	set("long", @LONG
你現在正棲身在一個山壁上勉強足以容納一個人休息的巖穴中，從
這裏無論是要往上爬或往下爬都有一段不算短的距離，最好先歇一歇，
喘口氣再走。
LONG
	);
	set("outdoors", "oldpine");

	setup();
}

void init()
{
	add_action("do_climb", "climb");
}

int do_climb(string arg)
{
	if( !arg || (arg!= "up" && arg!="down") )
		return notify_fail("你要往上(up)爬還是往下爬(down)？\n");

	if( arg=="up" ) {
		message_vision("$N試了試腳邊的岩石穩不穩，開始小心翼翼地往上攀爬。\n",
			this_player() );
		this_player()->move(__DIR__"cliffdown");
	} else if( arg=="down" ) {
		message_vision("$N試了試腳邊的岩石穩不穩，開始小心翼翼地往山澗中攀了下去。\n",
			this_player() );
		this_player()->move(__DIR__"epath3");
	}
	return 1;
}

