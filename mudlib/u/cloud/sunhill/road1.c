// Room: /u/sunhill/road1.c

inherit ROOM;

void create()
{
        set("short", "山腳小路");
        set("long", @LONG
這是條崎嶇的黃土小徑，北面通向渡口，往南小路蜿蜒而上，通往
山頂。
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"dukou",
  "southup" : __DIR__"road2",
  "east" : "/d/choyin/n_gate",
]));
        set("outdoors", "cloud");

        setup();
        replace_program(ROOM);
}

