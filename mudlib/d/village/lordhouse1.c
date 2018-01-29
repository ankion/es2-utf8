// Room: /d/village/lordhouse1.c

inherit ROOM;
#include <room.h>

void create()
{
	set("short", "財主家前院");
	set("long", @LONG
地主田老財的家似乎並不與老財的名字相適應，灰色的低矮院牆圍着
三間屋子。田老財家的前院，中間有一棵大槐樹，伸開的枝葉遮出一大片
陰涼，這裏連接東房和南房。前院的西面是一扇漆黑的大門。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"lordhouse3",
  "west" : __DIR__"road9",
  "east" : __DIR__"lordhouse2",
]));
	create_door("west","田老財家大門","east",DOOR_CLOSED);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
