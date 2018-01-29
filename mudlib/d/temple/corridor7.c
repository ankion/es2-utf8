// Room: /u/k/karrimor/temple/corridor7.c

inherit ROOM;

void create()
{
	set("short", "迴廊");
	set("long", @LONG
你正走在一條迴廊之上, 迴廊往南北延伸, 兩端分別連接著大殿
及後殿。西邊是一座花草扶蘇的天井, 東邊則是一排廂房。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
     "north" : __DIR__"corridor3",
     "south" : __DIR__"corridor1",
     "west" : __DIR__"inneryard",
     "east" : __DIR__"restroom1",
]));

    create_door("east","木門","west");

	setup();
}
