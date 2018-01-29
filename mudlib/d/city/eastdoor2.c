// eastdoor2.c
#include <room.h>

inherit ROOM;

string look_notice();

void create()
{
        set("short", "京師東二門");
        set("long", @LONG
這裏是京師的東二門。城門上插着幾面旗幟，標誌了本門的守
城將領。城樓裏坐着幾個將軍打扮的人，城牆上有一張剛剛粘貼上
去的佈告(notice)，一羣人正圍着觀看。東邊是城外，西邊是京師
的街道。
LONG
        );

        set("item_desc", ([
                "notice": (: look_notice :),
                "door": (: look_door, "out" :),
        ]) );

        set("exits", ([
//                "out"          : __DIR__"e2soad1",
                "west"          : __DIR__"street10" ]) );

        set("objects", ([
                __DIR__"npc/guard" : 3 ,]) );  

        create_door("out", "城門", "enter" );
        setup();
}

string look_notice()
{
     return "佈告上寫著：輯拿要犯----於蘭天武。\n";
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

