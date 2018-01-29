// /d/city/biaoju

inherit ROOM;

void create()
{
        set("short", "振遠總局");
        set("long",@LONG
你來到了振遠總局裏。鏢局雖然不大，但在京師這塊土地上，已無人
不知其名。尤其是其總鏢頭，儼然是以京城武林領袖自居。
LONG
        );

        set("exits", ([
		"south":	__DIR__"street1",
                ]));

	set("objects", ([
		__DIR__"npc/chen":	1,
		]) );

        setup();
        set("valid_startroom", 1);
        replace_program(ROOM);
}

