// Room: /d/snow/sroad1.c

inherit ROOM;

void create()
{
	set("short", "雪亭鎮街道");
	set("long", @LONG
這裏是雪亭鎮的街道，往北是一個熱鬧的廣場，南邊是條小路通往
一座林子，東邊則有一條小徑沿著山腰通往山上，往西是一條比較窄的
街道，參差不齊的瓦屋之間傳來幾聲犬吠。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"sroad2",
  "north" : __DIR__"square",
  "south" : "/u/cloud/dragonhill/nroad",
  "east" : __DIR__"eroad1",
]));
	set("outdoors", "snow");

	setup();
	replace_program(ROOM);
}
