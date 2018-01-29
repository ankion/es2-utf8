#include <room.h>

inherit ROOM ;

void create()
{
        set("short","絕地");
        set("long",@LONG
這是一塊絕地,四周沒有任何出口,你不禁急得要哭了出來,忽然,你發現
遠方有一塊大石(stone)動了一下,走近一看,似乎可以推(push)一下。
LONG
);

        set("outdoors","green");
        set("no_clean_up",0);
        setup();
//        replace_program(ROOM);
}

void init()
{
//        ::init();
        add_action("do_push","push");
}

int do_push(string arg)
{
        object me;
        
        if ( !arg || arg != "stone" )
                return notify_fail("你要推什麼?\n");
        
        me=this_player();
        
        if ( ((int)me->query("force") < 560) ||
             ((int)me->query("max_force") < 560) ||
             ((int)me->query("force_factor") < 40 ) ) { 
                tell_object(me, "你出力不太夠喔！\n");
                return 1;
        }

        me->receive_damage("gin",20);
        me->receive_damage("kee",60);
        me->receive_damage("sen",20);
        message_vision("$N用力推活動的大岩石,大岩石動了一下\n",me);
        
        if ( random(3) == 0 ) {
                message_vision("大岩石滾開了,$N從大岩石後面的小洞鑽了出去\n",me);
                this_player()->move(__DIR__"entrance");
                message("vision","$N從山壁上的一個洞口鑽了出來\n",environment(me),me);
        	tell_room(__DIR__"closed","風一吹,大岩石又滾了回來,把洞口又封住了\n");
                return(1);
        }
        return(1);
}


