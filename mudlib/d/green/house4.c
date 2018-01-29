// Room: /d/green/house4.c

inherit ROOM;

void create()
{
	set("short", "村長的家");
	set("long", @LONG
這是一間看起來有點不一樣的民宅，屋子的中央有一個石制的爐子，
上面生著一堆火，熊熊的火光把屋內照得像白天似的光亮。牆上掛著幾幅
字畫，一邊還放了一個木製的書架，上面整齊地排著一些舊得不能再舊的
書。爐子的旁邊擺了一張手工精美的石椅，看來像個很重要的位置。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : "/d/green/field0",
]));
	set("objects", ([
	"/d/green/npc/oldman2" : 1,
	]) );

	setup();
	replace_program(ROOM);
}

