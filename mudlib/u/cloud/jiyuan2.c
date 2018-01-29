// jiyuan2.c

#include <room.h>

inherit ROOM;

string look_sign(object me);

void create()
{
        set("short", "怡紅院二樓");
	set("long", @LONG
這是怡紅院的姑娘們陪客人們飲酒品茗，吟詩作賦的地方，甚是幽
雅。
LONG
        );
        set("exits", ([
                "down"  : "/u/cloud/jiyuan" ]) );

	set("objects", ([
                "/u/cloud/npc/girl" : 1,
	]) );

        setup();

}


