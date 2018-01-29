// Room: /d/choyin/yard.c

inherit ROOM;

void create()
{
	set("short", "庭院");
	set("long", @LONG
這是一間什麼也沒有的空房間。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"club",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
