// Room: /d/snow/crossroad.c

inherit ROOM;

void create()
{
	set("short", "山坳");
	set("long", @LONG
這裏是一處山坳，往南就是雪亭鎮，一條蜿蜒的小徑往東通往另一
個鄰近的小山村，一塊官府立的告示牌立在路旁，上面寫著有關野羊山
土匪出沒的警告標誌。
LONG
	);
	set("outdoors", "snow");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
		"north" : "/d/goathill/mroad1",
		"east" : "/d/green/path6",
		"south" : __DIR__"mstreet4",
]));

	setup();
	replace_program(ROOM);
}
