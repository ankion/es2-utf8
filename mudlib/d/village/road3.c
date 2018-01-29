// Room: /d/village/road3.c

inherit ROOM;

void create()
{
	set("short", "青石小路");
	set("long", @LONG
這是一條通向一個村莊的青石小路。路口立着一個小牌子(tablet)，
牌子看起來經過長時間的日曬雨淋，已破爛不堪。東南向望去好像是片
瓜地，綠油油的西瓜讓你感覺更渴了。從這裏往西就進了村子，向東到
三叉路口。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"road4",
  "east" : __DIR__"road2",
]));
	set("no_clean_up", 0);
	set("item_desc", ([
		"tablet":"你勉強分辨出那上面模糊的字跡：傅家坡\n"
	]) );
	setup();
	replace_program(ROOM);
}
