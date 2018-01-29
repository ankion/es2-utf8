// Room: /d/oldpine/npath1.c

inherit ROOM;

void create()
{
	set("short", "林間小路");
	set("long", @LONG
你現在正走在一條林間的小路，往北不遠處走出這座林子就是雪亭
鎮，小路兩旁長滿了許多高聳的松樹，雪亭鎮的居民都把這裏叫做「老
松林」，據說林子裏有株樹齡上千的老松樹，頗有靈驗。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : "/d/oldpine/npath2",
  "north" : "/d/snow/eroad3",
]));
	set("outdoors", "oldpine");

	setup();
	replace_program(ROOM);
}
