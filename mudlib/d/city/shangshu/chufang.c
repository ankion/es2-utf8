// /d/city/shangshu/road3

inherit ROOM;

void create()
{
        set("short", "廚房");
        set("long",@LONG
你來到了尚書府的廚房。廚房裏各種烹飪用品與設備應有盡有，
而且用品的做工也都很精細，一眼便知是官家的用品。廚房裏的爐火
燒得旺旺的，一個燒火丫鬟正忙着即將出鍋的「西湖醋魚」。
LONG
        );

        set("exits", ([
		"west":		__DIR__"road3",
                ]));

	set("objects", ([
		__DIR__"npc/maid": 	1,
		]) );

        setup();
        replace_program(ROOM);
}

