// Room: /d/waterfog/westhall.c

inherit ROOM;

void create()
{
	set("short", "水煙閣西側花廳");
	set("long", @LONG
這裏是水煙閣入口西側的花廳，東邊是水煙閣的正門，南邊和西邊
圍著一圈白玉欄杆，欄杆外種著許多茶花，往北是水煙閣的側門，從這
裏可以看到通往水煙閣二樓的階梯。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"north" : __DIR__"weststair",
		"east" : __DIR__"entrance",
]));

	setup();
	replace_program(ROOM);
}
