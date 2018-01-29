// Room: /u/k/karrimor/temple/sroad.c

inherit ROOM;

void create()
{
	set("short", "青石官道");
	set("long", @LONG
這是一條寬敞堅實的青石大道, 大道沿著山腰往南向山下延伸, 東
邊是一條石英岩石階蜿蜒往山上而去。在石階的盡頭, 是一座頗爲雄偉
的道觀, 在江湖跑過的人都知道, 那是茅山派的所在地。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
     "eastup" : __DIR__"ladder5",
     "west"   : "/d/snow/eroad3",
]));
	set("outdoors", "temple");

	setup();
	replace_program(ROOM);
}
