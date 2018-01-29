// Room: /d/goathill/slope1.c

inherit ROOM;

void create()
{
	set("short", "岩石坡");
	set("long", @LONG
這裏是一處岩石斜坡，斜坡上到處佈滿亂石及雜草，東邊的巖壁邊
有一間石屋，往西跟往北則可以回到鋪滿碎石的山路。
LONG
	);
	set("outdoors", "goathill");
	set("exits", ([ /* sizeof() == 2 */
		"north" : __DIR__"mroad6",
		"west" : __DIR__"mroad5",
]));

	setup();
	replace_program(ROOM);
}
