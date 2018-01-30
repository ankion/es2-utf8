// Room: /d/snow/school1.c
#include <room.h>

inherit ROOM;

void create()
{
	set("short", "淳風武館大門");
	set("long", @LONG
你現在正站在一間大宅院的入口，兩隻巨大的石獅鎮守在大門的兩
側，一陣陣吆喝與刀劍碰撞的聲音從院子中傳來。通過紅漆大門(door)
往東可以望見許多身穿灰衣的漢子正在操練。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : "/d/snow/mstreet1",
  "east" : "/d/snow/school2",
]));
	set("outdoors", "snow");
	set("objects", ([
		__DIR__"npc/guard": 1 ]) );

	create_door("east", "紅漆大門", "west", DOOR_CLOSED);

	set("item_desc", ([
		"door": (: look_door, "east" :),
	]) );

	setup();
	replace_program(ROOM);
}
