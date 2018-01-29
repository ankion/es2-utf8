// Room: /d/chuenyu/sunnyroad.c

inherit ROOM;

void create()
{
	set("short", "山腳鄉田");
	set("long", @LONG
你的兩側是茂盛的稻田，還有一條清澈見底的小溪。許多鄉民在田裏
辛苦的忙碌着。再北面是黑松山。眺望山頂，你似乎可以看到一個頗具規
模的城堡。城堡的最頂端插着一面大旗，大旗上繡着兩個斗大的金字：淳于。
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/flower_seller" : 1,
]));
	set("no_magic", 1);
	set("outdoors", "chuenyu");
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"base_b_m",
  //"south" : __DIR__"dustyroad3",
  "southwest" : __DIR__"croad2",
]));
	set("no_fight", 1);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
