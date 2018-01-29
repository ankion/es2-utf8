// Room: /u/k/karrimor/temple/corridor2.c

inherit ROOM;

void create()
{
	set("short", "迴廊");
	set("long", @LONG
你現在正走在一條迴廊上, 東北方是一座花木扶蘇的天井, 穿過
東邊的圓形拱門就可以回到大殿。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
     "north" : __DIR__"corridor6",
     "east" : __DIR__"temple1",
]));

	setup();
	replace_program(ROOM);
}
