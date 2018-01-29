// Room: /d/snow/w_room.c

#include <room.h>

inherit ROOM;

void create()
{
	set("short", "客房");
	set("long", @LONG
這是一間打掃得相當乾淨的客房，雖然所有的傢俱看起來都相當樸
素，比不上縣城裏幾家著名的大酒館，但是自有一種敦厚親切的感覺，
你在這裏相信可以安心的休息。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"east" : __DIR__"inn_2f",
	]));

	create_door("east", "房門", "west", DOOR_CLOSED);
	
	setup();
}
