
#include <room.h>
inherit ROOM;

void create()
{
    set("short", "二樓走廊");
	set("long", @LONG
你走在後廳二樓的走廊上，莊內像這樣的走廊很多，你若沒有地
理概念很容易迷路。長長的走道中, 純金鑄成的長燈架上掛了一排飾
麗的宮燈! 入夜之後燈火輝煌! 十分美麗!
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
    "west" :__DIR__"upstar2",
    "north" :__DIR__"upstarc",
    "south" :__DIR__"uproom3",

]));

    create_door("south","木門","north", DOOR_CLOSED);
	setup();
	replace_program(ROOM);
}
