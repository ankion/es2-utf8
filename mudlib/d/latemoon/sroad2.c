inherit ROOM;

void create()
{
        set("short", "蜿蜒小徑");
        set("long", @LONG
你走在這條蜿蜒的小徑上, 本來向北走的小徑被一道峭壁擋住了,
因此小徑從這彎向東邊去, 在你的西邊是一片雜草和幾棵小樹。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
          "northwest" :__DIR__"sroad1",
          "east" :__DIR__"sroad3",
]));

        set("outdoors", "latemoon");
        setup();
        replace_program(ROOM);
}
