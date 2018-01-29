// Room: /d/waterfog/wpath1.c

inherit ROOM;

void create()
{
	set("short", "山坡小徑");
	set("long", @LONG
你現在正走在一條山坡上的小徑，往南望去只見山下一條白色石階
蜿蜒上山，通往東邊不遠處的一個平臺，平臺的北邊就是赫赫有名的武
者聖地「水煙閣」，小徑的北邊整齊地種著一排楓樹，往西上了山坡通
往位於山巔的「虹臺」。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : "/d/waterfog/wpath2",
  "east" : "/d/waterfog/frontyard",
]));
	set("no_clean_up", 0);
	set("outdoors", "waterfog");

	setup();
	replace_program(ROOM);
}
