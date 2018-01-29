// eastdoor1.c
#include <room.h>

inherit ROOM;

string look_notice();

void create()
{
        set("short", "京師東一門");
        set("long", @LONG
你來到京師的東一門。城門口十來個手持刀槍的士兵正在檢查
過往的行人。經常有一些富麗堂皇的大車緩緩駛入城來，那是京師
的官宦人家出遊歸來。城牆上有一張陳舊的佈告(notice)。東邊是
城外，風景如畫。西邊是京師的街道。
LONG
        );

        set("item_desc", ([
                "notice": (: look_notice :),
                "door": (: look_door, "out" :),
        ]) );

        set("exits", ([
//                "out"          : __DIR__"e1soad1",
                "west"          : __DIR__"street9" ]) );

        set("objects", ([
                __DIR__"npc/guard" : 3, ]) );  

        create_door("out", "城門", "enter");
        setup();
}

string look_notice()
{
     return "佈告經風吹日曬，字跡已經不可分辨了。\n";
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
