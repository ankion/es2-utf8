// Room: /d/village/road1.c

inherit ROOM;

void create()
{
	set("short", "黃土大道");
	set("long", @LONG
這條黃土大道很寬闊，足夠供八架馬車並駕齊驅，與異族交戰時，大量
軍隊從此經過，和平時期只有商人來來往往。這條大道向南通往京師，往北
到天駝關。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"road2",
  "north" : "/d/canyon/canyon7",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
