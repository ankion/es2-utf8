
#include <room.h>
inherit ROOM;

void create()
{
     set("short", "綴芳閣");
	set("long", @LONG
這是晚月莊讓弟子們靜修的地方, 名曰「綴芳」。簡單的佈置加上
一座檀香爐, 你覺得這絕對是一個靜修(ponder)的好場所。空氣中瀰漫
著一股肅穆的氣息, 使人很容易進入忘我的境界。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
    "north" :__DIR__"upstar3",

]));

    set("objects", ([
        __DIR__"npc/huei" : 1,
     "/d/latemoon/obj/cake" : 1,
    ]) );
    create_door("north","木門","south", DOOR_CLOSED);
	setup();
}
void init()
{
       add_action("do_ponder","ponder");
}
int do_ponder(string arg)
{
       object who;

       who = this_player();
       message_vision("$N雙手合掌，安靜的坐在地上。\n" ,who);
       who->receive_damage("sen",50);
       if( (int)who->query("bellicosity") > 0)
           who->add("bellicosity", - (random((int)who->query("kar")) + 7 ) );
       message_vision("$N彷佛變的較爲祥合慈善了! \n" , who);
    return 1;
}
