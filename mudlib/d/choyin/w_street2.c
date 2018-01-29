// Room: /d/choyin/w_street2.c

inherit ROOM;

void create()
{
	set("short", "西大街");
	set("long", @LONG
這裏是喬陰縣城的西大街，西門就在你的西邊幾十丈外，望東則是
通往喬陰縣的著名地標「樹王墳」，街上有許多商店，北邊是一家大酒
樓，南邊則有一間染坊。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"w_street1",
  "east" : __DIR__"w_street3",
]));
	set("no_clean_up", 0);
	set("outdoors", "choyin");

	setup();
	replace_program(ROOM);
}
