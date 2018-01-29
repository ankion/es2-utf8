// Room: /u/cloud/nroad1.c

inherit ROOM;

void create()
{
        set("short", "東市場");
        set("long", @LONG
這裏是綺雲鎮的東市場，北面是藥店，東面是兵器店。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : "/u/cloud/nwroad3",
  "north" : "/u/cloud/drugstore",
  "south" : "/u/cloud/nroad2",
  "east" : "/u/cloud/weapony",
]));
        set("outdoors", "cloud");

        setup();
        replace_program(ROOM);
}

