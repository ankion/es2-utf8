// Room: /u/cloud/eroad3.c

inherit ROOM;

void create()
{
        set("short", "綺雲鎮街道");
        set("long", @LONG
這裏是綺雲鎮東頭，北面是張家，東南方就是茶場。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : "/u/cloud/rich",
  "southwest" : "/u/cloud/eroad2",
  "southeast" : "/u/cloud/eroad4",
]));
        set("outdoors", "cloud");

        setup();
        replace_program(ROOM);
}

