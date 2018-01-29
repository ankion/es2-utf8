// Room: /d/goathill/canyon1.c

inherit ROOM;

void create()
{
	set("short", "峽谷");
	set("long", @LONG
你現在正走在一條狹長的峽谷之中，東西兩邊都是高不可攀的峭壁
，一根五、六丈寬的石樑正橫跨在你頭頂的谷口，看起來搖搖欲墜，萬
一掉下來只怕當場就會被壓成一個肉餅，往南就是峽谷的出口，峽谷谷
底的地面看起來像是乾涸的山澗，彎彎曲曲往北通入峽谷深處。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"northdown" : __DIR__"canyon2",
		"south" : __DIR__"mroad6",
]));

	setup();
	replace_program(ROOM);
}
