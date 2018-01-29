// Room: /d/waterfog/weststair.c

inherit ROOM;

void create()
{
	set("short", "西側廳");
	set("long", @LONG
這裏是水煙閣西側的廳院，一道白石梯從這裏通往二樓，往北是僕
役的臥房跟柴房，南邊是出水煙閣的側門，往西則是一個可以眺望山谷
的陽臺。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
		"up" : __DIR__"west_2f",
		"north" : __DIR__"storage",
		"south" : __DIR__"westhall",
]));

	setup();
	replace_program(ROOM);
}
