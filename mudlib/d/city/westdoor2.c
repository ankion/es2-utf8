// westdoor2.c
#include <room.h>

inherit ROOM;

string look_notice();

void create()
{
        set("short", "京師西二門");
        set("long", @LONG
你來到京師的西二門，西二門雖不如京師的其他幾個城門高大。
但高高的城牆也非一般人所能攀越，城牆上貼着幾張佈告(notice)。
西邊是城外，據說一直往西就可到達一個仙境。東邊就是京師的街
道了。
LONG
        );

        set("item_desc", ([
                "notice": (: look_notice :),
                "door": (: look_door, "out" :),
        ]) );

        set("exits", ([
//                "out"          : __DIR__"w2soad1",
                "east"          : __DIR__"street13" ]) );

        set("objects", ([
                __DIR__"npc/guard" : 3 ,]) );  

        create_door("out", "城門", "enter" );
        setup();
}

string look_notice()
{
     return "佈告上寫著：行人出入需繳納一兩黃金。\n";
}

int valid_leave(object me,string dir)
{
        if ( dir=="out" &&
                ( !(string) me->query("marks/京師")
                || !(string) me->query("marks/令牌") ) ) {
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

