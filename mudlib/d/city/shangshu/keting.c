// /d/city/street5

#include <room.h>

inherit ROOM;

void create()
{
        set("short", "尚書府客廳");
        set("long",@LONG
這裏是尚書府的會客廳，平常主人就在此接待客人。客廳的裝飾
倒並不多，但都極其講究。所有的傢俱都是用沉香木做的，時時發出
一股淡淡的香味。傢俱被擦得一塵不染的，整齊地排列在兩旁。當中
的椅子尤其大，並鋪以少見的白虎皮。
LONG
        );

        set("exits", ([
                "west" :        __DIR__"yuan",
                ]));

	set("objects", ([
		__DIR__"npc/shangshu":	1,
		]));

        setup();
        replace_program(ROOM);
}

