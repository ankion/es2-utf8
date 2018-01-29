// Room: /d/goathill/mroad6.c

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
你現在正走在一條崎嶇的山路上，往北是一個峽谷，通過「飛火崖
」的正下方，從這裏可以看到一條五、六丈寬的石樑魏顫顫地跨過峽谷
，山路往西南轉過，南邊則是一片岩石斜坡。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
		"north" : __DIR__"canyon1",
		"southwest" : __DIR__"mroad5",
		"south" : __DIR__"slope1",
]));
	set("outdoors", "goathill");

	setup();
	replace_program(ROOM);
}
