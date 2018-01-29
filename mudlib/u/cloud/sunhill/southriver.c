// Room: /u/sunhill/southriver.c

inherit ROOM;

void create()
{
        set("short", "泓水南側");
        set("long", @LONG
這裏靠近南岸，江水甚是寒冷。從這兒已能望到山煙寺的一角。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"midriver",
  "south" : __DIR__"dukou",
]));
        set("outdoors", "cloud");

        setup();
        replace_program(ROOM);
}

