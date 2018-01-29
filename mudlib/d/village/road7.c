// Room: /d/village/road7.c

inherit ROOM;

void create()
{
	set("short", "青石小路");
	set("long", @LONG
小路的兩邊種了一排垂柳，西邊玉螺湖上的陣陣霧氣透過柳枝飄散過
來。你的東邊是一大片綠油油的瓜地，一條大溝橫在小路和瓜地之間，你
可以走到東南向的瓜棚。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "southeast" : __DIR__"melonguard",
  "south" : __DIR__"road8",
  "west" : __DIR__"lakeside",
  "northup" : __DIR__"road5",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
