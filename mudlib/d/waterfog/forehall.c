// Room: /d/waterfog/forehall.c

inherit ROOM;

void create()
{
	set("short", "聆嘯廳");
	set("long", @LONG
這裏是水煙閣二樓的聆嘯廳，南面是一個大露臺，按著西、西南、
南、東南、東等方向立著五塊灰綠色的怪石(stone)，東西各有一個出
口通往側廳，往北則是水煙閣主所居的春秋水色齋。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"west" : __DIR__"west_2f",
		"east" : __DIR__"east_2f",
	]));
	set("objects", ([
		__DIR__"npc/elder5" : 1,
		__DIR__"npc/elder6" : 1,
		__DIR__"npc/elder7" : 1,
	]) );
	setup();
	replace_program(ROOM);
}
