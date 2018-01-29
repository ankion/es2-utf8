// Room: /d/choyin/bridge4.c

inherit ROOM;

void create()
{
	set("short", "曲橋");
	set("long", @LONG
這是一座彎彎曲曲的曲橋，橫過翠柳湖連接東岸的雨橋莊跟西岸的
喬陰縣城，從這裏可以欣賞翠柳湖的美景，許多睡蓮散佈在橋墩四周，
湖面飄著數不盡的浮萍，浮萍底下有不少豔紅錦鯉穿梭來去。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"south" : __DIR__"bridge5",
		"west" : __DIR__"bridge3",
	]));
	set("outdoors", "choyin");
	set("objects", ([
		__DIR__"npc/girl" : 1,
		__DIR__"npc/maid" : 2,
	]) );

	setup();
	replace_program(ROOM);
}
