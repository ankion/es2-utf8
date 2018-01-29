// Room: /d/temple/broom2.c

inherit ROOM;

void create()
{
	set("short", "經樓");
	set("long", @LONG
上了樓來, 首先你看到一幅張天師的畫像掛在對面的牆上, 畫像
的下方擺著一張覆著紅布的桌子, 桌上整齊地放著茅山的鎮教祕籍。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "down" : "/d/temple/book_room1",
]));

	setup();
	replace_program(ROOM);
}
