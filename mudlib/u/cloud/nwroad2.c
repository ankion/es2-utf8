// Room: /u/cloud/nwroad2.c

inherit ROOM;

void create()
{
        set("short", "西市場");
        set("long", @LONG
這裏是綺雲鎮的西市場，西邊是家棺材鋪，南面是家布莊。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : "/u/cloud/woodboxy",
  "north" : "/u/cloud/nwroad1",
  "south" : "/u/cloud/tailory",
  "east" : "/u/cloud/nwroad3",
]));
        set("outdoors", "cloud");

        setup();
        replace_program(ROOM);
}

