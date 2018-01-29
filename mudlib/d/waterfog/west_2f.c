// Room: /d/waterfog/west_2f.c

inherit ROOM;

void create()
{
	set("short", "西側廳");
	set("long", @LONG
這裏是水煙閣西側廳的二樓，由於側廳是挑高建築，因此這裏只有
一條約七、八尺寬的走道連接樓梯與往東的門。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"down" : __DIR__"weststair",
		"east" : __DIR__"forehall",
	]));
	set("objects", ([
		__DIR__"npc/elite_guard": 2
	]) );

	set("waterfog_guard_dir", "east");
	setup();
	replace_program(ROOM);
}
