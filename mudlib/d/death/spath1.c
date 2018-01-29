// Room: /d/death/spath1.c

inherit ROOM;

void create()
{
	set("short", "牆邊小路");
	set("long", @LONG
這是一條沿著城牆的小路，東邊是一座高大巍峨的城樓，城樓前有
一條長長的石橋，橋上許多模糊的影子正列隊走進城門。小路往西南延
伸進入一片沼地。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"east" : __DIR__"gateway",
]));
	set("outdoors", "death");

	setup();
	replace_program(ROOM);
}
