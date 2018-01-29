// Room: /u/cloud/wroad2.c

inherit ROOM;

void create()
{
        set("short", "綺雲鎮街道");
        set("long", @LONG
這裏是綺雲鎮西，東邊就是十字路口。南面的院子裏甚是喧鬧，象
是有很多人的樣子。北面是雜貨鋪，不過門不朝這個方向開。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : "/u/cloud/wroad1",
  "south" : "/u/cloud/monky",
  "east" : "/u/cloud/cross",
]));
        set("outdoors", "cloud");

        setup();
        replace_program(ROOM);
}

