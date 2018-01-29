// Room: /d/choyin/s_street2.c

inherit ROOM;

void create()
{
	set("short", "福林大街");
	set("long", @LONG
這裏是喬陰縣城的福林大街，東首一棟雕樑畫棟，美侖美奐的華廈
便是喬陰縣最大的酒樓「福林樓」，不但喬陰縣城的富商大賈常來此樓
飲宴，就連方圓百里內的許多豪門巨紳也常常到這裏喝酒，西邊是一條
寬敞的青石官道，通往縣府衙門，街道往南則是熱鬧的南門廣場。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"s_street3",
  "south" : __DIR__"s_street1",
  "east" : __DIR__"hotel1",
]));
	set("no_clean_up", 0);
	set("outdoors", "choyin");

	setup();
	replace_program(ROOM);
}
