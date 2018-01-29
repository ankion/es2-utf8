// Room: /d/choyin/n_street1.c

inherit ROOM;

void create()
{
	set("short", "福林大街");
	set("long", @LONG
你現在正走在一條寬敞的街道上，這裏是喬陰縣城聯通北門與南
門的福林大街，街道兩旁有做生意的，有做粗活的，這裏的老百姓大多
是老老實實的農人與工匠，街上賣的也多半是一些日用品，往東邊是一
條小巷子，南邊的街道似乎比較熱鬧一些，北邊則是北門。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"n_street2",
  "north" : __DIR__"n_gate",
]));
	set("objects", ([
		__DIR__"npc/cake_vendor": 1,
		CLASS_D("beggar") + "/master": 1
	]) );
	set("outdoors", "choyin");

	setup();
	replace_program(ROOM);
}
