
#include <room.h>

inherit ROOM;

void create()
{
    set("short", "內書房");
	set("long", @LONG
這是一間安靜的書房, 光線適中。近窗邊有一張桌子，旁有書櫥! 
還有一個古琴放在平臺上! 牆上除了美麗的飾物外，還掛了一些書畫 
有一股濃郁清新的書香氣息! 
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
        "east" :__DIR__"lroad3",

]));

        set("objects", ([
            "/d/latemoon/npc/servant2" : 1,
            __DIR__"npc/spring1" : 1 ]) );
	setup();
	replace_program(ROOM);
}
