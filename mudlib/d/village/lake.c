// Room: /d/village/lake.c

inherit ROOM;

void create()
{
	set("short", "玉螺湖");
	set("long", @LONG
這裏是玉螺湖的湖心，湖面上絲絲霧氣蒸起，周圍靜得出奇，心跳聲
都聽的見。你仔細地向湖底看去，忽的見白光一閃，如果想看個究竟，可
以潛入湖中(dive)，但理智告訴你一定要安全第一！西面遠處是朦朧的羣
山，東邊岸上的漁夫似乎衝着你比比劃劃。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"lakeside",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

void init()
{
	add_action("do_paddle","paddle");
	add_action("do_dive","dive");
}

int valid_leave(object me,string dir)
{
	if( dir=="east" )
		return notify_fail("你正站在船頭，向東走一小步就會掉入湖中！你不想這樣吧？\n");
	return valid_leave( me,dir);
}

int do_paddle(string arg)
{
        if(!arg || arg=="")
                return notify_fail("你要劃什麼？\n");
        if( arg!="boat" && arg!="船" )
                return notify_fail("不划船你想劃什麼？\n");
        message_vision("$N你划動雙槳，小船慢慢向岸邊漂去。\n
", this_player());
        write("你終於劃到湖岸邊。\n");
        this_player()->move(__DIR__"lakeside");
        return 1;
}

int do_dive(string arg)
{
	message_vision("$N深深吸了一口氣，一個猛子潛入水中！\n", this_player() );
	write("你越潛越深，突然眼前一亮，一處湖底發出光亮。你用拳一砸，那\n
               湖底竟然碎了，原來是一層冰！你隨着水流被衝進一個巖洞中。\n");
	this_player()->move(__DIR__"lakebottom1");
	return 1;
}
