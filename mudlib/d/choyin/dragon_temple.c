// Room: /d/choyin/dragon_temple.c

inherit ROOM;

void create()
{
	set("short", "火龍將軍廟");
	set("long", @LONG
這裏是喬陰縣城香火最盛的火龍將軍廟，火龍將軍據說就是兩百年
前率領官兵和殺死樹王的骷髏妖怪作戰的黎方黎將軍，這裏就是當年火
龍將軍駐兵紮營之處，如果你想知道火龍將軍的事蹟，不妨問問附近的
年長的居民，將軍廟的建築十分奇特，一條道路東西貫通廟的中央，而
火龍將軍的神像立在橫跨道路的一個高臺上，往來的行人都從火龍將軍
的腳底走過，要上香的信徒必須從南北兩邊的階梯爬上高臺。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
		"up" : __DIR__"altar",
		"west" : __DIR__"s_gate",
		"east" : __DIR__"sw_road1",
	]));

	set("objects", ([
		__DIR__"npc/crone" : 1
	]) );

	set("no_fight", "1");
	set("no_magic", "1");

	setup();
	replace_program(ROOM);
}
