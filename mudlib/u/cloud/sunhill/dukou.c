// Room: /u/sunhill/dukou.c

inherit ROOM;

void create()
{
        set("short", "江南渡口");
        set("long", @LONG
這裏是泓水南岸，再往南不遠就是日照山了。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"southriver",
  "south" : __DIR__"road1",
]));
        set("outdoors", "cloud");

        setup();
}

