// Room: /d/snow/eroad2.c

inherit ROOM;

void create()
{
	set("short", "黃土小徑");
	set("long", @LONG
這是一條普通的黃土小徑，小徑往西南通往一處山間的平地，從這
裏可以望見不少房屋錯落在平地上，往北則一路上山。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"eroad3",
  "west" : __DIR__"eroad1",
]));
	set("outdoors", "snow");

	set("objects", ([
		__DIR__"npc/dog": 2 ]) );

	setup();
	replace_program(ROOM);
}
