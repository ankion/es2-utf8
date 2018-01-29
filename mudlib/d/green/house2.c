// Room: /d/green/house2.c

inherit ROOM;

void create()
{
	set("short", "民宅");
	set("long", @LONG
這是一間簡陋的民宅, 屋頂隱約還可以看到一些破洞. 牆角堆
著些柴火, 牆壁上還可以看到煙燻的痕跡. 除了一些簡陋的傢俱外
屋內空空蕩蕩的.
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : "/d/green/field0",
]));
	set("no_clean_up", 0);
	set("objects", ([
		"/d/green/npc/oldman" :1,
		"/d/green/npc/oldwoman" : 1,
		]) );

	setup();
	replace_program(ROOM);
}
