// Room: /d/sanyen/corridor1.c

inherit ROOM;

void create()
{
	set("short", "走廊");
	set("long", @LONG
你正走在一條長廊上, 兩旁分別是流雲軒及後殿的外牆, 牆上畫
著大慈大悲觀世音菩薩救苦救難的事蹟。長廊往東西兩邊延伸, 西邊
的盡是一間相當大的房屋。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"kitchen",
  "east" : __DIR__"corridor",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
