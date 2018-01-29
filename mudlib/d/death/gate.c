// Room: /d/death/gate.c

inherit ROOM;

void create()
{
	set("short", "[1;37m鬼門關[2;37;0m");
	set("long", @LONG
這裏就是著名的陰間入口「鬼門關」，在你面前矗立著一座高大的
黑色城樓，許多亡魂正哭哭啼啼地列隊前進，因爲一進鬼門關就無法再
回陽間了。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"south" : __DIR__"bridge",
		"north" : __DIR__"gateway",
]));
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/wgargoyle" : 1,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
