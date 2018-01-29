// Room: /d/temple/broom2.c

inherit ROOM;

void create()
{
	set("short", "書庫");
	set("long", @LONG
這是一間什麼也沒有的空房間。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "down" : "/d/temple/broom1",
]));

	setup();
	replace_program(ROOM);
}
