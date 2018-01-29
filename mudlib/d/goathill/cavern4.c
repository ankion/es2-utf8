// Room: /d/goathill/cavern4.c

inherit ROOM;

void create()
{
	set("short", "巖洞");
	set("long", @LONG
這裏是一處陰暗的巖洞，等你走近這個巖洞才發現原來是死路，東
北邊隱隱透出幾道微光，想必是洞穴的出口，地上一灘灘暗黃色的黏稠
物不知道士什麼東西，聞起來竟一點味道也沒有。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"northwest" : __DIR__"cavern1",
	]));
	set("objects", ([
		__DIR__"npc/worm": 2,
		__DIR__"npc/big_worm": 1
	]) );

	setup();
	replace_program(ROOM);
}
