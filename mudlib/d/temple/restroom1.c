// Room: /u/k/karrimor/temple/restroom.c
#include <room.h>

inherit ROOM;

void create()
{
	set("short", "廂房");
	set("long", @LONG
這是一間供香客或其他江湖同道休息掛單的客房, 屋子裏只是簡
單地擺放著幾件傢俱。從西邊的天井中, 傳來了陣陣的花香。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
            "west" : __DIR__"corridor7",
]));

        set("objects", ([
            "/d/temple/npc/old_taoist" : 1 ]) );

        create_door("west", "木門", "east");

	setup();
}
