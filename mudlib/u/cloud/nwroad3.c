// Room: /u/cloud/nwroad3.c

inherit ROOM;

void create()
{
        set("short", "中市場");
        set("long", @LONG
這裏是綺雲鎮的中市場，北面是茶樓，南面是雜貨鋪。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : "/u/cloud/nwroad2",
  "north" : "/u/cloud/tearoom",
  "south" : "/u/cloud/zaihuoy",
  "east" : "/u/cloud/nroad1",
]));
        set("outdoors", "cloud");

        set("objects", ([
                "/obj/npc/garrison" : 2,
        ]) );

        setup();
        replace_program(ROOM);
}

