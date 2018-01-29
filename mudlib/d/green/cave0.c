// tmp cave room until the cave section is done.
#include <room.h>
 
inherit ROOM;
 
void create()
{
        set("short", "洞口");
        set("long", @LONG
這裏是山洞的入口, 往南看去是一條小小的碎石路, 兩旁長滿
雜草, 看來很不明顯. 往北是一道厚厚的木門, 上面用一條手臂粗
的鐵鏈拴著. 雖然如此, 你仍可以感到一股寒氣從裏面透出來.
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "south" : "/d/green/path0",
  "north" : "/d/green/cave1",
]));
	create_door("north","木門","south",DOOR_CLOSED); 
	set("objects", ([
		"/d/green/npc/kid4" : 2,
		]) );
        setup();
        replace_program(ROOM);
}
 
