// Room: /d/choyin/yamen_yard.c
# include <room.h>
inherit ROOM;

void create()
{
	set("short", "縣衙內院");
	set("long", @LONG
院內草木繁茂,亭榭錯落有致,可見這位縣太爺也是位雅人.
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"court1",
  "north" : __DIR__"yamen",
]));
   create_door("north", "銅釘大門", "south", DOOR_CLOSED);   	
        set("no_clean_up", 0);
        set("objects", ([
                __DIR__"npc/magistra" : 4     
                         ]) ); 
	setup();
      replace_program(ROOM);
}
