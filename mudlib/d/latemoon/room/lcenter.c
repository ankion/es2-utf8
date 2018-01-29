
#include <room.h>
inherit ROOM;

void create()
{
    set("short", "後廳");
	set("long", @LONG
你進了後廳，這是後院上房五間中，最大的一間廳房。四面牆            
壁，玲瓏剔透，琴劍書畫，掛在牆上。錦籠紗罩，金彩珠光，連地上                  
踏的磚，皆是碧綠鑿花，是雕空的紫檀板壁。廳上擺了二十六張檜木
交椅，莊內對外展示舞步表演，都是在這舉行。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
     "east" :__DIR__"lroad1",
     "north" :__DIR__"twoc",
     "west" :__DIR__"lroad3",
     "south" :__DIR__"lstudio",

]));

    set("objects", ([
        __DIR__"npc/spring2" : 1,
        __DIR__"npc/yushou" : 1,
    ]) );
    create_door("north","後廳大門","south", DOOR_CLOSED);
	setup();
	replace_program(ROOM);
}
