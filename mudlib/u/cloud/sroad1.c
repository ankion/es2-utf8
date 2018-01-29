// Room: /u/cloud/sroad1.c

inherit ROOM;

void create()
{
        set("short", "綺雲鎮街道");
        set("long", @LONG
這裏是綺雲鎮南，通往過江的渡口。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"cross",
  "south" : __DIR__"dukou",
]));
        set("outdoors", "cloud");

        setup();
        replace_program(ROOM);
}

