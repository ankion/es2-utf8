// Room: /d/graveyard/grave1.c

inherit ROOM;

void create()
{
	set("short", "亂葬崗");
	set("long", @LONG
你現在正站在一處亂葬崗的草叢裏，放眼望去四面都是一墳墳的土
堆，裏面想必埋的都是一些客死異鄉，又無親無故的可憐人，被好心的
鄉人收埋在這裏，因爲長年乏人整理，這裏的雜草密佈，幾達人腰，崗
上到處開滿了俗稱「望鄉紅」的小紅花，也許是吸收了土裏屍骨的養分
，這裏的紅花開得又大又詭異。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"southeast" : __DIR__"road1",
]));
	set("outdoors", "graveyard");

	setup();
	replace_program(ROOM);
}
