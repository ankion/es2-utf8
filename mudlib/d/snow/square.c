// Room: /d/snow/square.c

inherit ROOM;

void create()
{
	set("short", "廣場");
	set("long", @LONG
這裏是雪亭鎮鎮前廣場的空地，地上整齊地鋪著大石板。廣場中央有
一個木頭搭的架子，經過多年的風吹日曬雨淋，看來非常破舊。四周建築
林立。往西你可以看到一間客棧，看來生意似乎很好。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
		"north" : __DIR__"mstreet1",
		"west" : __DIR__"inn",
		"south" : __DIR__"sroad1",
		"east" : __DIR__"temple",
	]));
	set("objects", ([
//		__DIR__"npc/worker": 4
		"/d/snow/npc/trav_blade" : 3,
	  ]) );

	set("outdoors", "snow");

	setup();
	replace_program(ROOM);
}
