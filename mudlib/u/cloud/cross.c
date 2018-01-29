// Room: /u/cloud/square.c

inherit ROOM;

void create()
{
        set("short", "十字路口");
        set("long", @LONG
綺雲鎮的兩條青石路在這裏交叉，路旁栽着棵古槐，有兩個漢子合
抱那麼粗。槐樹下有個告示，象是官府立的。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"wroad2",
  "north" : __DIR__"nroad2",
  "south" : __DIR__"sroad1",
  "east" : __DIR__"eroad1",
]));
        set("outdoors", "cloud");

        setup();
        replace_program(ROOM);
}

