// Room: /d/village/road2.c

inherit ROOM;

void create()
{
	set("short", "三叉路口");
	set("long", @LONG
這裏已經離天駝關很遠了，順着黃土大道向南走，綠色漸漸多了起
來，樹木透着喜人的綠，放眼望去青山綠水，好一派關內景色，你能看
到散落的房屋，農田和水塘。來往的旅客、商人、農民也多了。黃土大
道向東南方向延伸，西面是進入一個村莊的小路。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south"	 	 : "/d/city/nroad2",
  "north" : __DIR__"road1",
  "west" : __DIR__"road3",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/trader1" : 2,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
