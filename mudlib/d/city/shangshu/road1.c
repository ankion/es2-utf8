// /d/city/shangshu/road1

#include <room.h>

inherit ROOM;

void create()
{
        set("short", "小徑");
        set("long",@LONG
尚書府的小徑走到這似乎到了盡頭。小徑的東邊是一間小屋，平
時房門總是關的，每天按時由一名又聾又啞的僕役送飯進去，其他人
一概不讓入內。南邊不遠處就是尚書府庭院了。
LONG
        );

        set("exits", ([
                "east" :        __DIR__"xiaowu",
		"south":	__DIR__"road2",
                ]));

	set("objects", ([
		__DIR__"npc/huyuan":	1,
		]) );

	set("outdoors", "city");
	
	create_door ("east", "小木門", "west", DOOR_CLOSED);

        setup();
        replace_program(ROOM);
}

