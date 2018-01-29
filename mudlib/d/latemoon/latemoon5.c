
#include <room.h>
inherit ROOM;

void create()
{
    set("short","後院走道");
	set("long", @LONG
你走在一條長廊上，兩旁都是庭臺堂廡，廊上瀰漫著一股
香郁的氣息，廊下是由青石磚鋪成，一邊接後廳內院，一邊的
盡頭則是一幅大石壁畫，西側似有一銅門(door)。
有一間書房。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
    "west" :__DIR__"latemoon6",
    "south" :__DIR__"latemoonc",

]));

     create_door("west","銅門","east", DOOR_CLOSED);
	setup();
	replace_program(ROOM);
}
