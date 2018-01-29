// Room: /u/cloud/dragonhill/hummock.c

inherit ROOM;

void create()
{
        set("short", "臥龍崗");
        set("long", @LONG
這是位於雪亭和綺雲兩鎮間的一道山樑。據說山上時常有強盜攔路
搶劫。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "northdown" : __DIR__"nhillfoot",
  "southdown" : __DIR__"shillfoot",
]));

        set("objects", ([
                "/u/cloud/npc/gangster" : 2
]) );

        set("outdoors", "dragonhill");

        setup();
}
