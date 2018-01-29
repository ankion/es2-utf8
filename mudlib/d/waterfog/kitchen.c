// Room: /d/waterfog/kitchen.c

inherit ROOM;

void create()
{
	set("short", "廚房");
	set("long", @LONG
這裏是水煙閣的廚房，東首一座大竈，竈邊堆著許多瓦甕，北邊是
一張方桌，桌上鍋碗瓢盆一應俱全，西邊則是一個櫥櫃，往南可以回到
廳中。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"south" : __DIR__"eaststair",
]));

	setup();
	replace_program(ROOM);
}
