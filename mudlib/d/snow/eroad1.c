// Room: /d/snow/eroad1.c

inherit ROOM;

void create()
{
	set("short", "黃土小徑");
	set("long", @LONG
這是一條普通的黃土小徑，彎彎曲曲往東一路盤旋上山，北邊有
一間城隍廟，往西則是雪亭鎮的街道。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"eroad2",
  "north" : __DIR__"temple",
  "west" : __DIR__"sroad1",
]));
	set("outdoors", "snow");

	setup();
	replace_program(ROOM);
}
