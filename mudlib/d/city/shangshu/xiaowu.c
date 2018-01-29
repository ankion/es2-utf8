// /d/city/shangshu/xiaowu

#include <room.h>

inherit ROOM;

void create()
{
        set("short", "小屋");
        set("long",@LONG
你步入尚書府內的一間小屋。小屋內很黑，什麼也看不見，但莫
名地感到一股殺氣，讓人有轉身就跑的念頭。
LONG
        );

        set("exits", ([
		"west":		__DIR__"road1"
                ]));

	create_door ("west", "小木門", "east", DOOR_CLOSED);

        setup();
        replace_program(ROOM);
}

