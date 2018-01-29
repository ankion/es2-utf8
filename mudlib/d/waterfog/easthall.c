// Room: /d/waterfog/easthall.c

inherit ROOM;

void create()
{
	set("short", "水煙閣東側花廳");
	set("long", @LONG
這裏是水煙閣正門東邊的花廳，東邊和南邊圍著一圈白石欄杆，欄
杆外種著許多茶花，往西是水煙閣的正門，往北則是東側的側廳，從這
裏可以看見通往二樓的階梯。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"north" : __DIR__"eaststair",
		"west" : __DIR__"entrance",
]));

	setup();
	replace_program(ROOM);
}
