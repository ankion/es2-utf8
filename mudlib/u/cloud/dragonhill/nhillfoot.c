// Room: /u/cloud/dragonhill/nhillfoot.c

inherit ROOM;

void create()
{
        set("short", "臥龍崗北坡");
        set("long", @LONG
從這往西北有條路通往雪亭鎮，向南爬就是臥龍崗。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "northwest" : __DIR__"nroad",
  "southup" : __DIR__"hummock",
]));
        set("outdoors", "dragonhill");

        setup();
        replace_program(ROOM);
}
