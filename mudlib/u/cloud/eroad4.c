// Room: /u/cloud/eroad4.c

inherit ROOM;

void create()
{
        set("short", "茶場");
        set("long", @LONG
這裏是綺雲鎮的茶場，綺雲盛產茶葉，因此這裏有不少茶工在忙着
採茶。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "northwest" : "/u/cloud/eroad3",
]));

        set("objects", ([
                "/u/cloud/npc/worker" : 6,
        ]) );

        set("outdoors", "cloud");

        setup();
        replace_program(ROOM);
}

