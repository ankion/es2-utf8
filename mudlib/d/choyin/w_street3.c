// Room: /d/choyin/w_street3.c

inherit ROOM;

void create()
{
	set("short", "西大街");
	set("long", @LONG
這裏是喬陰縣城的西大街，東邊不遠處的石臺便是遠近馳名的「樹
王墳」，西大街往西一直通往西城門，街道兩邊有許多的商店，街上人
來人往好不熱鬧。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"nw_street",
  "west" : __DIR__"w_street2",
  "east" : __DIR__"tree_tomb",
]));
	set("no_clean_up", 0);
	set("outdoors", "choyin");

	setup();
	replace_program(ROOM);
}
