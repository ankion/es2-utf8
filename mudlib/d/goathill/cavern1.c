// Room: /d/goathill/cavern1.c

inherit ROOM;

void create()
{
	set("short", "巖洞");
	set("long", @LONG
這個巖洞的內部似乎遠比你想像得大，巖壁上有一條條的深溝彷佛
是被什麼蛀蟲給蛀出來的，可是有什麼蟲會去啃咬這又硬又厚的巖壁呢
？洞穴的出口在你的西邊透著微光，東北邊跟西北邊各有一個洞穴，黑
暗中似乎有什麼東西在蠕蠕而動。
LONG
	);
	set("no_clean_up", 0);
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/worm" : 2,
]));
	set("exits", ([ /* sizeof() == 3 */
		"southeast" : __DIR__"cavern4",
		"northeast" : __DIR__"cavern2",
		"west" : __DIR__"canyon3",
]));

	setup();
	replace_program(ROOM);
}
