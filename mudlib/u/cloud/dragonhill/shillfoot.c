// Room: /u/cloud/dragonhill/shill.c

inherit ROOM;

void create()
{
        set("short", "臥龍崗南坡");
        set("long", @LONG
這是臥龍崗的東南坡。東南的路通向綺雲鎮，往北就要過崗了。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "northup" : __DIR__"hummock",
  "southeast" : "/u/cloud/entrance"
]));
        set("outdoors", "dragonhill");

        setup();
        replace_program(ROOM);
}
