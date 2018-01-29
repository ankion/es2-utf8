#include <room.h>

inherit ROOM;

void create()
{
   set("short", "西廂房");
	set("long", @LONG
你進入西廂房來，地下面西放著四張椅子，都搭著銀紅撒花椅被
椅子兩邊有一對高几，右邊几上文王鼎，匙筋香盒；左邊几上汝窯美
人瓶內插著花卉茗琬棰壺等物。隔窗望去，隱約可看見花園景色。.
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
    "east" :__DIR__"wroad2",

]));

       set("objects", ([
        __DIR__"npc/servant" : 1,
        __DIR__"npc/annihi" : 1 ]) );
    create_door("east","雕飾房門","west", DOOR_CLOSED);
	setup();
	replace_program(ROOM);
}
