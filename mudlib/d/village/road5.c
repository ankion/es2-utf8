// Room: /d/village/road5.c

inherit ROOM;

void create()
{
	set("short", "青石小路");
	set("long", @LONG
青石小路在這裏分成兩條，一條繼續向西延伸，另一條伸向南面，北
面是一個鮮花盛開的小花園，聞到陣陣花香，你不僅心曠神怡。西面遙遠
處是連綿的羣山，東南是一片面積不小的湖泊。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"road6",
  "north" : __DIR__"littlegarden",
  "southdown" : __DIR__"road7",
  "east" : __DIR__"road4",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
