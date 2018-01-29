// Room: /u/k/karrimor/temple/corridor7.c
#include <room.h>

inherit ROOM;

void create()
{
	set("short", "迴廊");
	set("long", @LONG
你現在走在圍繞著天井的迴廊上, 迴廊往東西兩側延伸, 南邊就
是天井, 你也許可以走過去賞賞花, 散散心。在你的北方, 走過那扇
紅漆木門就是後殿, 也是茅山派供奉歷代掌門人靈位的地方。
LONG
	);
     set("item_desc", ([
         "door": (: this_object(), ({ "look_door", "north"}) :),
     ]));
	set("exits", ([ /* sizeof() == 3 */
     "west" : __DIR__"corridor4",
     "east" : __DIR__"corridor3",
     "south" : __DIR__"inneryard",
     "north" : __DIR__"temple2",
]));

     create_door("north", "紅漆木門", "south", DOOR_CLOSED);
	setup();
}
