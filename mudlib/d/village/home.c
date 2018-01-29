// Room: /d/village/home.c
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "劉家小房");
	set("long", @LONG
這是一所很破舊的木屋。每當山風吹來，都會發出“吱吱呀呀”
的聲音。南側是一個小小的廚房。木屋的後面是一個精巧的花園，花
園裏穿來陣陣打鬧之聲。一個翠綠的小草坪就在西面。
LONG
	);
	set("item_desc", ([ /* sizeof() == 1 */
  "south" : (: look_door,     "south" :),
	]));
	set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"smallstorage",
  "south" : __DIR__"littlegarden",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/oldliu" : 1,
]));
	create_door("south", "木門", "north", DOOR_CLOSED);
	set("no_clean_up", 0);

	setup();
}
