// Room: /d/green/temple0.c

inherit ROOM;

void create()
{
	set("short", "土地廟");
	set("long", @LONG
這是一間小小的土地廟, 廟內相當的暗, 一股溼氣混上焚燒冥
紙的味道使得屋內的的氣味顯得很奇特. 供桌上零星地放個一些水
果, 一尊木刻的土地公像孤獨地立在前面. 廟外的小空地邊有一個
簡陋的金紙亭.
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : "/d/green/path2",
]));

	setup();
	replace_program(ROOM);
}
