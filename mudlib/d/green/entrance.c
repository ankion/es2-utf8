#include <room.h>

inherit ROOM;

void create()
{
        set("short","山路盡頭");
        set("long",@LONG
你走到了山路的盡頭，發現三面都是石壁，東面石壁上有一個洞口，洞內隱隱
發出風雷之聲，洞口上方似乎刻着一副圖(painting)，北面是一扇大石門，
門上苔跡斑斑，顯然已經很久沒人打開過了。
LONG
);
        set("exits",([ /* sizeof() == 3 */
                "north": __DIR__"outdoor",
                "east" : __DIR__"eight0",
                "south": __DIR__"mpath2",
        ])
	);
        create_door("north","大石門","south", DOOR_CLOSED);
        set("item_desc",([ 
        "painting":"這是一副八卦陣圖,圖下面有一行模糊的小字：八卦古陣\n"
        ]) 
        );

        set("no_clean_up",0);
        setup();
}

int valid_leave(object me,string dir)
{
        if ( dir == "east" && me->query("combat_exp") < 100000 ) 
                return notify_fail("你向石洞走去，忽然一陣狂風涌至，你抵受不住，只好退了回來\n");
        if ( dir == "east" ) {
		tell_room(environment(me),(string)me->query("name")+
        "向石洞走去，接着便消失在迷霧之中......\n",
        ({this_object(), me}));
	return 1 ;
	}
         else   return ::valid_leave(me,dir);
}

