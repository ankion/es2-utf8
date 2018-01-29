// Room: /d/choyin/yamen.c
# include <room.h>
inherit ROOM;

void create()
{
	set("short", "大堂");
	set("long", @LONG
正中高懸一匾(borad),匾下的書案上放着筆,墨,紙,硯,驚堂木等物.兩旁各置屏風.堂下襬着各式刑具,你從未見過.
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
                "north" : __DIR__"yamen_iner",
                "south" : __DIR__"yamen_yard",
                      ]));
   create_door("south", "銅釘大門", "north", DOOR_CLOSED);
	set("no_clean_up", 0);
 set("objects", ([
                __DIR__"npc/judgeman" : 1,     
                __DIR__"npc/magistra" : 2,
                __DIR__"npc/yamen_po" : 8     
                 ]) ); 	
        setup();
	replace_program(ROOM);
}
