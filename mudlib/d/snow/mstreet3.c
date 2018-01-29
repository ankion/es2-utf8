// Room: /d/snow/mstreet3.c

#include <room.h>

inherit ROOM;

void create()
{
	set("short", "雪亭鎮街道");
	set("long", @LONG
這裏是雪亭鎮的大街，東邊有一棟陳舊的建築，看起來像是什麼店
鋪，但是並沒有任何招牌，只有一扇門(door)上面寫著一個大大的「當
」字，往西是一間藥鋪，大街往南北兩個方向延伸。
LONG
	);

	set("exits", ([
		"south"	: __DIR__"mstreet2",
		"north"	: __DIR__"mstreet4",
		"east"	: __DIR__"hockshop",
		"west"	: __DIR__"herbshop",
	]));
	set("outdoors", "snow");

	setup();

	create_door("east", "店鋪門", "west", DOOR_CLOSED);

	replace_program(ROOM);
}
