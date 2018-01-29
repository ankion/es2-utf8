// Room: /u/sunhill/road4.c

inherit ROOM;

void create()
{
        set("short", "盤山小徑");
        set("long", @LONG
這是條崎嶇的黃土小徑。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"road3",
  "southwest" : "/d/sanyen/sroad1",
]));
        set("outdoors", "cloud");

        setup();
        replace_program(ROOM);
}

