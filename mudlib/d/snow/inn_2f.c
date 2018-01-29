// Room: /d/snow/inn_2f.c

#include <room.h>

inherit ROOM;

void create()
{
	set("short", "飲風客棧二樓");
	set("long", @LONG
你現在來到了飲風客棧的二樓，這家客棧有個很奇怪的規矩，就是隻留宿
名頭夠大的客人，如果你只是一個無名小卒，不論出再多銀兩都租不到一間空
房，牆邊有一道樓梯通往一樓的茶座。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
		"west" : __DIR__"w_room",
		"north" : __DIR__"n_room",
		"down" : __DIR__"inn",
		"east" : __DIR__"e_room",
	]));
	
	set("objects", ([
		__DIR__"npc/rat":	6,
		]));

	create_door("north", "房門", "south", DOOR_CLOSED);
	create_door("east", "房門", "west", DOOR_CLOSED);
	create_door("west", "房門", "east", DOOR_CLOSED);

	setup();
}
