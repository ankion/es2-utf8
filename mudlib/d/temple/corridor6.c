// Room: /u/k/karrimor/temple/corridor6.c

inherit ROOM;

void create()
{
	set("short", "迴廊");
	set("long", @LONG
你正走在一條迴廊之上, 迴廊往南北延伸, 兩端分別連接著大殿
及後殿。東邊是一座花草扶蘇的天井, 西邊是一間上了鎖的房間。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
     "south" : __DIR__"corridor2",
     "north" : __DIR__"corridor4",
     "east" : __DIR__"inneryard",
]));

	setup();
	replace_program(ROOM);
}
