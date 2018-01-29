
#include <room.h>
inherit ROOM;

void create()
{
   set("short", "儀門");
	set("long", @LONG
你走在後廳內院的儀門，是晚月莊後廳內院長廊走道的相接路
口。東北方是往膳房的夾道，西面是長廊夾道，南面是到後廳，往北
則可走出大門前往前院。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
    "north" : "/d/latemoon/latemoon4",
    "south" :__DIR__"lcenter",
    "east" :__DIR__"eat1",
    "west" :__DIR__"two1",

]));

    create_door("south","後廳大門","north", DOOR_CLOSED);
	setup();
	replace_program(ROOM);
}
