// Room: /d/canyon/stone_forest2.c

inherit ROOM;

void create()
{
	set("short", "黃石穿林路");
	set("long", @LONG
草壓天頂的情況依舊，唯西側亮光逐漸顯明，看來西側的不遠處
有一出口，黃石斑斑，挾雜著白色的圓點，像是白色光束長期照射的
結果，蒙朧的景色在此總算完全的清淅了，向東側仍是回到路口的路
，而西側的亮光直直吸引你往深處探索。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"west" : __DIR__"stone_forest3",
		"east" : __DIR__"stone_forest1",
]));

	setup();
	replace_program(ROOM);
}
