// Room: /d/canyon/canyon6.c

inherit ROOM;

void create()
{
	set("short", "天駝關谷地");
	set("long", @LONG
高聳的懸崖立在天駝關兩側，中間是並不開闊的谷地，真是易守難
攻的好地方，這麼多年來與異族的關係一直非常緩和，因此大門又重新
打開。鐵門的後面有個很大的機械裝置(machine)，向南是通往京城的
路，往北就出了天駝關。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"canyon7",
  "north" : __DIR__"canyon5",
]));
	set("item_desc", ([ /* sizeof() == 1 */
  "mechine" : "這是個很大的絞盤，可能是開關鐵門用的。\n",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
