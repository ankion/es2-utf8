// tea_corridor.c

#include <room.h>

inherit ROOM;

string look_sign();

void create()
{
	set("short", "香茗坊茶窖");
	set("long", @LONG
茶窖裏有幾個大竹籮，裏面裝滿了茶葉。 
LONG
        );

        set("exits", ([
                "south"          : "/u/cloud/tearoom",
	]) );

//	set("objects", ([
//	]) );

        create_door("south", "木雕門", "north", DOOR_CLOSED);

        setup();

}


