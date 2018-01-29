
#include <room.h>
inherit ROOM;

void create()
{
     set("short","後院走道");
	set("long", @LONG
你走在一條長廊上，兩旁都是庭臺堂廡，廊上瀰漫著一股
香郁的氣息，長廊向東西方延伸而去。東邊是後廳院子，西邊
有一間書房。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
    "south" :__DIR__"latemoon8",
    "east" :__DIR__"latemoonc",
    "west" :__DIR__"latebook",

]));

   create_door("south","石門","north", DOOR_CLOSED);
	setup();
	replace_program(ROOM);
}
