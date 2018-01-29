// croad1.c
#include <room.h>

inherit ROOM;

void create()
{
        set("short", "黃土大道");
        set("long", @LONG
你正走在一條黃土大道上。路上塵土飛揚，路旁稀疏幾棵矮樹。
往南通往京師，東北是通往天駝關的大道。
LONG
        );

        set("exits", ([
                "south"      : "/d/village/road1",
		"north" 	 : __DIR__"croad2" ]) );

/*        set("objects", ([
                "/u/cp/chater2" : 1, ]) );*/
        set("outdoors", "chuenyu");
        setup();
        replace_program(ROOM);
}

