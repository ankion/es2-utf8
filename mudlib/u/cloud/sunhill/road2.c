// Room: /u/sunhill/road2.c

inherit ROOM;

void create()
{
        set("short", "盤山小徑");
        set("long", @LONG
這是條崎嶇的黃土小徑。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"road1",
  "west" : __DIR__"road3",
]));
        set("outdoors", "cloud");

        setup();
        replace_program(ROOM);
}

