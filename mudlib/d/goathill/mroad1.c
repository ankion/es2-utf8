// Room: /d/goathill/mroad1.c

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
你現在正走在一條崎嶇的山路上，凹凹凸凸的山石刺得你的腳底隱
隱生疼，山路往南不遠處通往一個山腰的臺地，這一帶最大的鎮甸就位
在臺地上，東邊跟西邊都是陡峭的山壁，山路往北通往層層疊疊的羣山
之中。
LONG
	);
	set("outdoors", "goathill");
	set("exits", ([ /* sizeof() == 2 */
		"north" : __DIR__"mroad2",
		"south" : "/d/snow/crossroad",
]));

	setup();
	replace_program(ROOM);
}
