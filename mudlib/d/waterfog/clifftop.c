// Room: /d/waterfog/clifftop.c

inherit ROOM;

void create()
{
	set("short", "水煙閣半山亭");
	set("long", @LONG
這裏是一個用白石砌成的亭子，亭子的東面和北面都是深不見底的
懸崖，從這裏望出去只見一片雲霧之中突出幾座山峯，雲霧之中隱隱可
以看到好似水波的微光，使你一時之間彷佛以爲這座亭子是建在一個湖
中，往西北望去可以看到水煙閣漂浮在雲霧之中。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "westup" : "/d/waterfog/stair5",
  "southdown" : "/d/waterfog/stair4",
]));
	set("objects", ([
		__DIR__"npc/watcher": 1,
		__DIR__"npc/celes_tiger": 1 ]) );
	set("outdoors", "waterfog");

	setup();
	replace_program(ROOM);
}
