// Room: /d/graveyard/road1.c

inherit ROOM;

void create()
{
	set("short", "黃土小徑");
	set("long", @LONG
這是一條鋪著黃土的小徑，彎彎曲曲地穿過一片夾雜著矮樹叢跟雜
草的斜坡，往西南通往一條比較開闊的大路，西北邊則是一片亂葬崗。
LONG
	);
	set("outdoors", "graveyard");
	set("exits", ([ /* sizeof() == 1 */
    "northwest" : __DIR__"grave1",
  ]));

	setup();
	replace_program(ROOM);
}
