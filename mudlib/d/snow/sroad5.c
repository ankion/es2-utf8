// Room: /d/snow/sroad5.c

inherit ROOM;

void create()
{
	set("short", "青石官道");
	set("long", @LONG
這是一條寬敞堅實的青石板大道，大道兩旁種著整齊的花木，從這
裏往西通往水煙閣，往南則是銜接雪亭鎮街道的路口。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : "/d/waterfog/sroad1",
  "south" : __DIR__"sroad4",
]));
	set("outdoors", "snow");

	setup();
	replace_program(ROOM);
}
