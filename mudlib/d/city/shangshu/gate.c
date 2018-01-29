// /d/city/street5

#include <room.h>

inherit ROOM;

void create()
{
        set("short", "尚書府大門");
        set("long",@LONG
你來到尚書府大門。門上懸掛着一塊很大的黑色牌匾，上面用隸
書寫着三個金字「尚書府」。牌匾上的一行小字表明這是當今皇上所
題，可以看出其官勢顯赫。
LONG
        );

        set("exits", ([
                "west" :        "/d/city/street3",
                "east" :        __DIR__"yuan",
                ]));

	set("objects", ([
		__DIR__"npc/guard":	1,
		]));

        set("outdoors", "city");

	create_door ("east", "大鐵門", "west", DOOR_CLOSED);

        setup();
}

int valid_leave(object me,string dir)
{
        if ( dir=="east" &&  present("guard", environment(this_player()))
		&& !(string)me->query("marks/尚書") )
        return notify_fail("門房伸手攔住了你的去路，喝道：闖什麼闖！\n");

	if ((string)me->query("marks/尚書") )
		me->set("marks/尚書",0);
        return ::valid_leave(me,dir);
}

