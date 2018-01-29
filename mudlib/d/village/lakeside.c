// Room: /d/village/lakeside.c

inherit ROOM;

void create()
{
	set("short", "玉螺湖畔");
	set("long", @LONG
玉螺湖以產的螺螄潔白如玉而得名，並且湖中盛產味道鮮美的鱸魚。
有很多漁夫泛舟湖上，以網魚捕螺爲生。但現在他們都站在岸邊，面帶愁
容，不清楚有什麼變故發生。岸邊還散落了幾艘木船(boat)。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"lake",
  "east" : __DIR__"road7",
]));
	set("objects",([
		__DIR__"npc/fisher":3,
	]) );
	
	set("item_desc", ([
		"boat":
		"關內能經常見到的漁船，你可以划着(paddle)它到湖中心。
" ]) );
	set("no_clean_up", 0);

	setup();
	//replace_program(ROOM);
}

void init()
{
	add_action("do_paddle", "paddle");
}

int do_paddle(string arg)
{
	if(!arg || arg=="")
		return notify_fail("你要劃什麼？\n");
	if( arg!="boat" && arg!="船" )
		return notify_fail("不划船你想劃什麼？\n");
	message_vision("$N跳上漁船，奮力向湖心劃去。\n", this_player());
	write("你終於劃到湖中心了。\n");
	this_player()->move(__DIR__"lake");
	return 1;
}

int valid_leave(object me,string dir)
{
        if( dir=="west" )
            return notify_fail( "這麼大的一片湖，你想走過去嗎？\n" );
        return ::valid_leave(me,dir);
}
