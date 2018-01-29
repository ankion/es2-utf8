// Room: /d/goathill/cavern2.c

inherit ROOM;

void create()
{
	set("short", "巖洞");
	set("long", @LONG
你現在正在一個黑漆漆的巖洞中摸索前進，西南邊隱隱有些光亮，
想必是洞穴的出口，東邊似乎有些滴水的聲音，不過你得走過去才能聽
得仔細，你感覺腳邊有一些東西在蠕蠕而動，舉腳又有些黏黏的，一陣
噁心的感覺壓迫著你的胃。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"east" : __DIR__"cavern3",
		"southwest" : __DIR__"cavern1",
	]));
	set("objects", ([
		__DIR__"npc/fat_worm" : 1,
		__DIR__"npc/worm" : 3,
	]) );

	setup();
	replace_program(ROOM);
}
