// Room: /d/choyin/s_street4.c

inherit ROOM;

void create()
{
	set("short", "承安街");
	set("long", @LONG
這裏是喬陰縣城城南的承安街，街道十分寬敞，南北兩邊都是一些
販賣南北貨、日用品的商店，這裏雖然正當喬陰縣人車來往最頻繁的要
衝，可是卻沒有福林大街熱鬧，往東走便是南門廣場，往西則是和昌平
街的交叉路口。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"west" : __DIR__"s_street5",
		"east" : __DIR__"s_street1",
]));
	set("no_clean_up", 0);
	set("outdoors", "choyin");

	setup();
	replace_program(ROOM);
}
