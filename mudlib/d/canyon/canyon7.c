// Room: /d/canyon/canyon7.c

inherit ROOM;

void create()
{
	set("short", "天駝關谷地");
	set("long", @LONG
天駝關兩邊是懸崖，中間是谷地，形狀很象駱駝的雙峯，由此得名。
這裏地勢險峻，南下通往京師，北上除了“關外綠洲”雪亭鎮外就是異族
的領地了，歷來是兵家必爭之地。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"south" : "/d/village/road1",
  		"north" : __DIR__"canyon6",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
