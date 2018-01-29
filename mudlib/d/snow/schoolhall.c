// Room: /d/snow/schoolhall.c

inherit ROOM;

void create()
{
	set("short", "淳風武館大廳");
	set("long", @LONG
這裏是淳風武館的正廳，五張太師椅一字排開面對著門口，這是武
館中四位大師傅與館主柳淳風的座位，和一般武館不同的是，牆上竟然
掛著幾幅風骨頗爲不俗的書畫，顯示這裏的主人並非大字不識的粗漢，
而是文武雙全的高人。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"school2",
  "east" : __DIR__"inneryard",
]));
	set("objects", ([
		CLASS_D("swordsman") + "/master":1 ]) );
	set("valid_startroom", 1);
	setup();
	replace_program(ROOM);
	"obj/board/swordsman_b"->foo();
}
