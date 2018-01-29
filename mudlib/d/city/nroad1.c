#include <room.h>

inherit ROOM;

void create()
{
        set("short", "北驛道");
        set("long", @LONG
你正走在一條青石鋪地的大驛道上，四周人來人往。挑擔子的
苦力，趕着大車的馬伕，赴京傳書的軍人，熙熙攘攘，非常熱鬧。
不時還有兩三騎快馬從身邊飛馳而過，引起一陣騷動。道路兩旁各
有一片小樹林，南邊就是京師。
LONG
        );

        set("exits", ([
                "north"          : "/d/city/nroad2",
                "south"          : "/d/city/northdoor" ]) );

        set("outdoors", "city"); 
        create_door("enter", "城門", "out" );
        setup();
        replace_program(ROOM); 
}
void init()
{
	add_action("do_yell","yell");
}
void do_yell()
{
	if(!query("exit/up")) 
	   set("exits/up",__DIR__"room");
}
