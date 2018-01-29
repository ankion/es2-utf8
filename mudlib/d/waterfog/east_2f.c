// Room: /d/waterfog/east_2f.c

inherit ROOM;

void create()
{
	set("short", "東側廳");
	set("long", @LONG
這裏是水煙閣東側廳的二樓，由於側廳是挑高建築，因此這裏只有
一條約七、八尺寬的走道連接樓梯與往西的門。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"west" : __DIR__"forehall",
		"down" : __DIR__"eaststair",
	]));
	set("objects", ([
		__DIR__"npc/elite_guard": 2
	]) );

	set("waterfog_guard_dir", "west");
	setup();
	replace_program(ROOM);
}
