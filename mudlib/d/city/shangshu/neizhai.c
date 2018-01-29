// /d/city/shangshu/neizhai
#include <room.h>

inherit ROOM;

void create()
{
        set("short", "內宅");
        set("long",@LONG
你輕輕地走進尚書府的內宅，男客一般是不讓來此的。內宅的布
置很素雅，一切的擺設都顯得很自然，有「天然去雕飾，清水出芙蓉
」的意味。西邊就是你來時經過的花園。
LONG
        );

        set("exits", ([
		"west":		__DIR__"huayuan",
                ]));

	set("objects", ([
		__DIR__"npc/qing_chen":		1,
		]) );

	create_door("west", "簾子", "east", DOOR_CLOSED);

        setup();
        replace_program(ROOM);
}

