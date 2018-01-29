
#include <room.h>
inherit ROOM;

void create()
{
     set("short", "佛堂");
	set("long", @LONG
這是專供莊內祭祀的佛堂，是一座精構樓閣，屋頂覆以琉璃瓦，四
角鑽尖覆以鎏金銅瓦。堂內供奉  人靈「區冥」，旁有雨神「天龍」、
火神「鳳凰」。兩翼有琉璃鶴照壁，姿態生動。四周置陳神□佛像，□
盤塔磬，及一股檀香的氣息。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
     "east" :__DIR__"upcenter",

]));

    set("objects", ([
        __DIR__"npc/statue" : 1,
    ]) );
    create_door("east","檀香木門","west", DOOR_CLOSED);
	setup();
	replace_program(ROOM);
}
