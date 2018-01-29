// /d/city/shangshu/road2

#include <room.h>

inherit ROOM;

void create()
{
        set("short", "小徑");
        set("long",@LONG
這裏是尚書府的小徑。小徑繼續向北延伸着，透過樹叢隱隱約約
地看到那兒似乎有一間小屋。從這兒向東走就是一間客房，據說客房
裏住的是一位貴客。不過一般人不允許進。
LONG
        );

        set("exits", ([
		"north":	__DIR__"road1",
                "east" :        __DIR__"kefang",
		"south":	__DIR__"yuan",
                ]));

	set("objects", ([
		__DIR__"npc/huyuan":	1,
		__DIR__"npc/huyuan1":	1,
		]) );

	set("outdoors", "city");
	
	create_door ("east", "木門", "west", DOOR_CLOSED);

        setup();
}

int valid_leave(object me,string dir)
{
        if ( dir!="south" &&  present("trainer", environment(this_player()))
                && !(string)me->query("marks/尚書") )
        return notify_fail("護院伸手攔住了你的去路，喝道：闖什麼闖！\n");

        return ::valid_leave(me,dir);
}


