// tea_corridor.c

#include <room.h>

inherit ROOM;

void create()
{
	set("short", "場院前廳");
	set("long", @LONG
    這裏是這座場院的前廳，簡單的陳設中透出一股尊貴不凡的氣派。
一張黑漆鑲金的八仙桌擺放在大廳中央，兩隻黝黑的太師椅座在這張桌
子的兩旁。
LONG
        );

        set("exits", ([
                "east"          : "/u/cloud/god1",
	]) );

	set("objects", ([
	"/u/cloud/npc/god" : 1,]) );

        setup();

}


