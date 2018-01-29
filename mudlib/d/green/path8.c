// Room: /d/green/path8.c

inherit ROOM;

void create()
{
	set("short", "小巷子");
	set("long", @LONG
這是一條小小的巷子，地上鋪著碎石和黃土。南北各有一棟建築，不
過南方的屋子出口不在這邊。往東可以看到一個小小的廣場，往西則是一
個三岔路口。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : "/d/green/path3",
  "north" : "/d/green/house1",
  "east" : "/d/green/field0",
]));
	set("outdoors", "green");
	set("objects", ([
	"/d/green/npc/kid3" : 2,
	]) );

	setup();
	replace_program(ROOM);
}
