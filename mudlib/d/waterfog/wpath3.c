// Room: /d/waterfog/wpath3.c

inherit ROOM;

void create()
{
	set("short", "白石階梯");
	set("long", @LONG
你正走在一道白石階梯上，這道階梯依著山壁而建，東邊隔著一個
深不見底的山谷可以望見對面傲立在山巔之上的水煙閣，每當清晨山谷
中的晨霧慢慢飄起，從這裏可以看見水煙閣彷佛飄在雲間，這就是水煙
十景中的「飛天樓閣」，石階沿著山壁從這裏轉往北方。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : "/d/waterfog/wpath4",
  "south" : "/d/waterfog/wpath2",
]));
	set("no_clean_up", 0);
	set("outdoors", "waterfog");

	setup();
	replace_program(ROOM);
}
