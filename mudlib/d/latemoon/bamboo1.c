inherit ROOM;

void create()
{
        set("short", "竹林");
        set("long", @LONG
這是一座茂密的竹林。當你進入後彷佛迷失了方向！
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
          "east" :__DIR__"bamboo",
          "west" :__DIR__"bamboo1",
          "north" :__DIR__"bamboo2",
          "south" :__DIR__"bamboo4",
        ]));
        set("outdoors", "latemoon");
        setup();
        replace_program(ROOM);
}
