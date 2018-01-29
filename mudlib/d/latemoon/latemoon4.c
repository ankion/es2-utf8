
#include <room.h>
inherit ROOM;

void create()
{
    set("short","內廳穿堂");
	set("long", @LONG
你從後廊往西出了內廳進入穿堂。往北是內院，一條寬過道，西  
面立著一個粉油大影壁，後有一大半門，小小的一所庭宇。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"north" :__DIR__"latemoonc",
		"south" : "/d/latemoon/room/twoc",
		"east" : "/d/latemoon/latemoon2",
	]));


	create_door("east","儀門","west", DOOR_CLOSED);
	setup();
}
