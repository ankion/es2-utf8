// Room: /u/k/karrimor/temple/entrance.c
#include <room.h>

inherit ROOM;

void create()
{
	set("short", "靈心觀廣場");
	set("long", @LONG
你正站在靈心觀前的廣場前, 一片用石英岩鋪成的廣場。一對雄
偉的石獅子站在廟門的兩側, 獅子的兩側立著兩根雕著龍紋的石柱。
廣場的中央還有一個大香爐, 香爐里正冒著嫋嫋的香菸。
LONG
	);

     set("item_desc", ([
         "door": (:this_object(), ({"look_door", "north"}): ),
     ]) );

	set("exits", ([ /* sizeof() == 2 */
     "north" : __DIR__"temple1",
     "south" : __DIR__"entrance",
]));

     create_door("north", "紅漆木門", "south");

     set("outdoors", "temple");

	setup();
//	replace_program(ROOM);
}
