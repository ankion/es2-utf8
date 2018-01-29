// southdoor.c
#include <room.h>

inherit ROOM;

string look_notice();

void create()
{
        set("short", "京師西一門");
        set("long", @LONG
你來到京師的西一門。城牆上貼着幾張官家佈告(notice)。東
北方是大相國寺，不時傳來幾聲鐘聲。西邊是城外，擡頭可見遠處
連綿的羣山。東邊就是京師的街道了。
LONG
        );

        set("item_desc", ([
                "notice": (: look_notice :),
                "door": (: look_door, "out" :),
        ]) );

        set("exits", ([
//                "out"          : __DIR__"w1soad1",
                "east"          : __DIR__"street14" ]) );

        set("objects", ([
                __DIR__"npc/guard" : 3 ,]) );  

        create_door("out", "城門", "enter" );
        setup();
}

string look_notice()
{
    return "佈告上寫著：近來有土匪出沒，望行人小心。\n";
}

int valid_leave(object me,string dir)
{
        if ( dir=="out" &&
                ( !(string) me->query("marks/京師")
                 && !(string) me->query("marks/令牌") ) ) {
                tell_object (me, "京師守城兵說道：沒有官府通令，任何人不能出入京師。\n");
                return notify_fail("出城方向的路被京師守城兵擋住了。\n");
                }

        if (me->query("marks/令牌")) {
                ::valid_leave(me,dir);
                me->set("marks/令牌", 0);
                return 1;
                }

        return ::valid_leave(me,dir);
}
