// Room: /d/choyin/s_street5.c

inherit ROOM;

void create()
{
	set("short", "承安街");
	set("long", @LONG
這裏是喬陰縣城南的承安街，往東可以通往熱鬧的南門廣場，西邊
的路口則是通往縣府衙門的昌平街，街道北邊是一些販賣日常用具的商
店，南邊則是一塊空地，從這裏可以看到南邊的城牆。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"west" : __DIR__"crossroad",
		"east" : __DIR__"s_street4",
]));
	set("outdoors", "choyin");

	setup();
	replace_program(ROOM);
}
