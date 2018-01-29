// park.c

#include <room.h>

inherit ROOM;

string look_sign(object me);

void create()
{
        set("short", "張家花園");
	set("long", @LONG
你現在正站在張家花園裏
LONG
        );
        set("exits", ([
                "south"          : "/u/cloud/eroad2" 
        ]) );
        set("objects", ([
                "/u/cloud/npc/thief" : 1,
        ]) );

        setup();

}

