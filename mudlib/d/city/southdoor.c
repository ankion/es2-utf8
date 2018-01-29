// southdoor.c
#include <room.h>

inherit ROOM;

string look_notice(object me);

void create()
{
        set("short", "京師南門");
        set("long", @LONG
這是京師的南門。高大的城門正上“京師南門”幾個大字格外
顯眼。城牆上貼着幾張官家佈告(notice)。西北方是京師的監獄，
關押着一些要犯，因此這裏的官兵們也戒備森嚴。南邊是城外，不
時走來幾個赴京趕考的舉子。北邊就是京師，一個燈紅酒綠的地方。
LONG
        );

        set("item_desc", ([
                "notice": (: look_notice :),
                "door": (: look_door, "out" :),
        ]) );

        set("exits", ([
//                "out"          : __DIR__"ssoad1",
                "north"          : __DIR__"street17" ]) );

        set("objects", ([
                __DIR__"npc/guard" : 3 ,]) );  

        create_door("out", "城門", "enter");
        setup();
}

string look_notice(object me)
{
       if( wizardp(me) )
                return "告示上寫著：懸賞捉拿靈兒、阿泰。\n";
        else
                return "告示上寫著：今年文武大選。\n";
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

