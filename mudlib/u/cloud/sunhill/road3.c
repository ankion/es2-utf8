// Room: /u/sunhill/road3.c

inherit ROOM;

void create()
{
        set("short", "盤山小徑");
        set("long", @LONG
這是條崎嶇的黃土小徑。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"road2",
  "south" : __DIR__"road4",
]));
        set("outdoors", "cloud");

        setup();
        replace_program(ROOM);
}

