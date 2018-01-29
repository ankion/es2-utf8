// Room: /d/choyin/tomb2.c

inherit ROOM;

void create()
{
	set("short", "樹王墳內部");
	set("long", @LONG
這裏是樹王墳樹洞的內部，你的北、西、南三面都是盤根錯節的樹
根，地面上鋪著一堆乾草，似乎有人睡過的樣子，往東的出口通往樹洞
的另一端。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"tomb1",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
