// Room: /d/goathill/mroad3.c

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
你現在正走在一條崎嶇的山路上，東邊的路旁一個山壁的裂縫裏有
一間小廟，從這裏看過去黑漆漆的似乎沒有人照顧，山路往北是一段陡
峭的上坡，往西南的山路就平緩得多。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
		"northup" : __DIR__"mroad4",
		"east" : __DIR__"temple1",
		"southwest" : __DIR__"mroad2",
]));
	set("outdoors", "goathill");

	setup();
	replace_program(ROOM);
}
