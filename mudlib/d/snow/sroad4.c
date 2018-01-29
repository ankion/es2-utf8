// Room: /d/snow/sroad4.c

inherit ROOM;

void create()
{
	set("short", "青石官道");
	set("long", @LONG
這是一條寬敞堅實的青石板大道，大道兩旁種著整齊的花木，從這
裏往北通往水煙閣，往東則是銜接雪亭鎮街道的路口。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"sroad5",
  "east" : __DIR__"sroad3",
  "southwest" : "/d/canyon/road",
]));
	set("outdoors", "snow");
	set("objects", ([
		__DIR__"npc/crazy_dog": 1 ]) );

	setup();
	replace_program(ROOM);
}
