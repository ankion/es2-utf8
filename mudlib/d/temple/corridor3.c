// Room: /d/temple/corridor3.c

inherit ROOM;

void create()
{
	set("short", "迴廊");
	set("long", @LONG
你正站在迴廊轉角的地方, 迴廊從這往西及南邊而去。在走廊
的東側是一排廂房。北方是一條鋪著青石板的小徑。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
		"north" : __DIR__"road1",
		"south" : __DIR__"corridor7",
		"west" : __DIR__"corridor5",
		"east" : __DIR__"restroom2",
]));

        create_door("east","木門","west");

	setup();
}
