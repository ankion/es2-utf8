// Room: /d/oldpine/keep3.c

inherit ROOM;

void create()
{
	set("short", "老鬆寨");
	set("long", @LONG
這裏就是老鬆寨的大廳了，靠北邊的地面上鋪了一張巨大的熊皮，
上面擺了三張椅子，大廳四周散落著幾個取暖用的火盆，幾個上了鎖的
木箱子，比較奇特的是中央掘了一個大坑(pool)，坑裏是許多頭骨浸在
一種發著惡臭的黃水之中。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"west" : __DIR__"keep2",
	]));
	set("objects", ([
		__DIR__"npc/bandit_leader": 3,
		__DIR__"npc/bandit_commander":1
	]) );

	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
