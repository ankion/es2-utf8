// Room: /u/k/karrimor/temple/temple2.c
#include <room.h>

inherit ROOM;

void create()
{
	set("short", "後殿");
	set("long", @LONG
你正站在靈心觀的後殿, 正中央供奉著茅山派開山祖師張天師的
畫像, 在畫像的下方擺放著當年張天師收妖伏魔時所用的寶劍。劍的
兩旁陪祀著歷代掌門人的牌位。走出南邊的紅漆木門可以看到天井。
LONG
	);
    set("item_desc", ([
         "door": (: this_object(), ({ "look_door", "south"}) :),
    ]) );
	set("exits", ([ /* sizeof() == 1 */
     "south" : __DIR__"corridor5",
]));

     create_door("south", "紅漆木門", "north", DOOR_CLOSED);
	setup();
}
