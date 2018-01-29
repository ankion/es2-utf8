inherit ROOM;

void create()
{
        set("short", "小徑");
        set("long", @LONG
條蜿蜒的小徑通往東南方, 在你的東面是一道峭壁, 而在你的
南邊是一片濃密的竹林。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
          "northwest" :__DIR__"sroad2",
          "east" :__DIR__"sroad4",
]));

        set("outdoors", "latemoon");
        setup();
        replace_program(ROOM);
}
