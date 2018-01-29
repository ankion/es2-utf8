// Room: /d/choyin/s_street1.c

inherit ROOM;

void create()
{
	set("short", "南門廣場");
	set("long", @LONG
這裏便是喬陰縣城最大的一處廣場，往北是貫通縣城南北門的福林
大道，往東則是一個綠柳環繞的湖泊「翠柳湖」，廣場上只見賣藝的，
賣糖葫蘆的，捏麪人的，各色小販穿梭來去，廣場中央有一口大井，井
旁用繩索綁著幾隻杯子供人取水喝(drink)，南門的牌樓因爲幾年前改建
翠柳湖的曲橋，因此移到西邊的縣府衙門所在的昌平街，現在廣場的南
面就是一座曲橋通往湖東岸的雨橋莊，西南邊一條寬敞的街道沿著湖岸
通往城外，廣場的西邊則一直延伸到昌平街。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"south" : __DIR__"bridge1",
		"north" : __DIR__"s_street2",
		"west"	: __DIR__"s_street4",
		"southwest" : __DIR__"sw_road1",
	]));
	set("objects", ([ /* sizeof() == 2 */
		__DIR__"npc/cucurbit_seller" : 1,
		__DIR__"npc/dumpling_seller" : 1,
	]));
	set("resource/water", 1);
	set("outdoors", "choyin");
	setup();
}

void init()
{
	add_action("do_drink", "drink");
}

int do_drink(string arg)
{
	if( (int)this_player()->query("water") >=
		(int)this_player()->max_water_capacity() )
		return notify_fail("你已經再也喝不下一滴水了。\n");
	message_vision("$N在井邊用杯子舀起井水喝了幾口。\n", this_player());
	this_player()->add("water", 20);
	return 1;
}
