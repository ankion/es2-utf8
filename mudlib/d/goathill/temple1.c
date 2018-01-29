// Room: /d/goathill/temple1.c

inherit ROOM;

void create()
{
	set("short", "小土地廟");
	set("long", @LONG
你現在正站在一間小土地廟中，這座廟的南北兩面都是利用了山壁
而建的，只有東面一面土牆，牆上嵌著一個小小的神龕，裏面供著一尊
殘破不堪的土地爺爺，廟門在你的西邊。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"west" : __DIR__"mroad3",
	]));
	set("objects", ([
		__DIR__"npc/bandit_hwang" : 1,
	]) );

	setup();
	replace_program(ROOM);
}
