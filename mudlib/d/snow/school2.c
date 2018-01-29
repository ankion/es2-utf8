// Room: /d/snow/school2.c

#include <room.h>

inherit ROOM;

void create()
{
	set("short", "淳風武館教練場");
	set("long", @LONG
你現在正站在一個寬敞的教練場中，地上鋪著黃色的細砂，許多人
正在這裏努力地操練著，北邊是一間高大的兵器廳，往東則是武館師父
們休息的大廳。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : "/d/snow/weapon_storage",
  "west" : "/d/snow/school1",
  "east" : "/d/snow/schoolhall",
]));
	set("objects", ([ /* sizeof() == 2 */
  "/d/snow/npc/trainee" : 6,
  "/d/snow/npc/fist_trainer" : 1,
]));
	set("outdoors", "snow");

	create_door("west", "紅漆大門", "east", DOOR_CLOSED);
	setup();
	replace_program(ROOM);
}
