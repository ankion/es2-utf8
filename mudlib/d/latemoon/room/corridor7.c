#include <room.h>

inherit ROOM;

void create()
{
   set("short", "內廳");
	set("long", @LONG
你進了內廳，迎面掛著蔥綠灑花軟簾，掀簾進去，擡頭一看，
只見四面牆壁，玲瓏剔透，琴劍書畫，掛在牆上。錦籠紗罩，金彩
珠光，連地上踏的磚，皆是碧綠鑿花，左一架書，右一架屏。四面
是雕空的紫檀板壁。
LONG
	);
    set("exits", ([
    "south" :__DIR__"flower1",
    "east" : "/d/latemoon/room/eroad1",
    "west" : "/d/latemoon/room/wroad2",
    ]));
    set("objects", ([
        __DIR__"npc/yuchoun" : 1,
    ]) );

   create_door("south","垂花門","north", DOOR_CLOSED);

	setup();
	replace_program(ROOM);
}
