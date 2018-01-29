// Room: /d/choyin/e_street1.c

inherit ROOM;

void create()
{
	set("short", "東大街");
	set("long", @LONG
    這裏是喬陰縣城的東大街，西邊不遠處的石臺便是遠近馳名的「樹
王墳」，東大街往東一直通往東城門，街道兩邊有許多的民宅，街上行
人漸稀。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"tree_tomb",
  "east" : __DIR__"e_gate",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
