// Room: /d/choyin/n_street2.c

inherit ROOM;

void create()
{
	set("short", "福林大街");
	set("long", @LONG
你現在正走在一條寬敞的街道上，這裏是喬陰縣聯通南北城門的福
林大街，街道從這裏向南北延伸，往北遠遠地可以望見北門的石牌樓，
南邊不遠處則是喬陰縣城著名的地標「樹王墳」，你的東邊有一家三層
樓的酒館，西邊則是遠近馳名的老姚布莊，街上不時有販夫走卒穿梭
而過，十分熱鬧。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"n_street3",
  "north" : __DIR__"n_street1",
]));
	set("no_clean_up", 0);
	set("outdoors", "choyin");

	setup();
	replace_program(ROOM);
}
