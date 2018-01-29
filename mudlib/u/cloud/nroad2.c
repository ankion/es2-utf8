// Room: /u/cloud/nroad2.c

inherit ROOM;

void create()
{
        set("short", "南市場");
        set("long", @LONG
這裏是綺雲鎮的南市場，西面是雜貨鋪，向東可看到 怡紅院 的二樓。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : "/u/cloud/zaihuoy",
  "north" : "/u/cloud/nroad1",
  "south" : "/u/cloud/cross",
]));
        set("outdoors", "cloud");

        setup();
        replace_program(ROOM);
}

