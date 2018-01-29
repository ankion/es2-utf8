// Room: /u/cloud/nwroad1.c

inherit ROOM;

void create()
{
        set("short", "北市場");
        set("long", @LONG
這裏是綺雲鎮的北市場，再向北就是鎮口了。
    一股茶香與腥羶相混合的氣味撲鼻而來，西首鋪子外掛着個牛頭;
東面是家二層的茶樓，金字招牌十分晃眼。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : "/u/cloud/butchery",
  "north" : "/u/cloud/entrance",
  "south" : "/u/cloud/nwroad2",
  "east" : "/u/cloud/tearoom",
]));
        set("outdoors", "cloud");

        setup();
        replace_program(ROOM);
}

