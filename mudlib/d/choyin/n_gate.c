// Room: /d/choyin/n_gate.c

inherit ROOM;

void create()
{
	set("short", "喬陰縣城北門");
	set("long", @LONG
這裏喬陰縣城的北門，一座高大的石牌樓上面刻著「北門」兩個大
字，一條黃土路往北穿過一片松樹林，青鬱郁地通往北邊的山上，石牌
樓旁蹲著兩隻石獅，由於喬陰縣城最熱鬧的火龍將軍廟遠在城南，因此
北門這一帶反而顯得比較冷清，和附近的鄉村一般的寧靜純樸。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		// "north" : "/d/oldpine/spath4",
		"west"  : "/u/cloud/sunhill/road1",
		"south" : __DIR__"n_street1",
	]));
	set("objects", ([
		__DIR__"npc/cityguard": 2,
		__DIR__"npc/ghost": 1,
		"/obj/npc/garrison": 2,
	]) );
	set("outdoors", "choyin");

	setup();
	replace_program(ROOM);
}
