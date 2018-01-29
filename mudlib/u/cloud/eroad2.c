// Room: /u/cloud/eroad2.c

inherit ROOM;

void create()
{
        set("short", "綺雲鎮街道");
        set("long", @LONG
這裏是綺雲鎮東，通往茶場的路。南邊是一家有名的大鏢局 -- 振
遠鏢局。北面是綺雲張家的宅院。

LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : "/u/cloud/eroad1",
  "north" : "/u/cloud/park",
  "south" : "/u/cloud/biaoju",
  "northeast" : "/u/cloud/eroad3",
]));
        set("outdoors", "cloud");

        setup();
        replace_program(ROOM);
}

