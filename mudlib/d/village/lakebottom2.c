// Room: /d/village/lakebottom2.c

inherit ROOM;

void create()
{
	set("short", "水下巖洞");
	set("long", @LONG
水下巖洞到了這裏，突然變得非常寬闊，巨大的穹頂成半透明，能模
糊地看到頂外的小魚游來游去。自上而下的看去，你不僅倒吸一口冷氣：
幾隻白色的大龍或懸浮在空中、或盤在冰面上、或慢遊在洞裏的水潭中。
西面有一冰制的階梯盤旋而上，不知伸向哪裏。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "westup" : __DIR__"valley1",
  "eastdown" : __DIR__"lakebottom1",
]));
	set("objects", ([
		__DIR__"npc/dragon":6, 
	]) );
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
