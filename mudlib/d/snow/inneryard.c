// Room: /d/snow/inneryard.c

inherit ROOM;

void create()
{
	set("short", "天井");
	set("long", @LONG
這裏是淳風武館中的天井，往西走可以回到正廳，往北邊是書房，
南邊是招待客人的廂房，往東一條長廊通往武館內院，天井中種滿了許
多奇花異草，中央立著一根石柱(pillar)，上面似乎刻著字。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "south" : "/d/snow/guestroom",
  "north" : "/d/snow/nyard",
  "west" : "/d/snow/schoolhall",
  "east" : "/d/snow/innerhall",
]));
	set("item_desc", ([ /* sizeof() == 1 */
  "pillar" : "石柱上刻著：劍氣指天、劍心內斂、劍芒不顯、劍神如電。
",
]));
	set("no_clean_up", 0);
	set("outdoors", "snow");

	setup();
	replace_program(ROOM);
}
