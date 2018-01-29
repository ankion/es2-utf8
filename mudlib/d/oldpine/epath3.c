// Room: /d/oldpine/epath3.c

inherit ROOM;

void create()
{
	set("short", "林間小路");
	set("long", @LONG
你現在正走在一條松樹林間的小路，西邊有一座小石橋橫跨在一條
山澗上，往東不遠處似乎是林子的出口，一條破舊的棧道沿著山壁通往
山上，你發現地上有一些溼漉漉的腳印(footprints)，但是因爲腳印太
多，分不出是往哪裏去。
LONG
	);
	set("item_desc", ([ /* sizeof() == 1 */
		"footprints" : "一些雜亂的腳印，不但有人的腳印，看起來還有不少馬蹄印。\n",
	]));
	set("exits", ([ /* sizeof() == 1 */
		"west" : __DIR__"epath2",
	]));
	set("objects", ([
                __DIR__"npc/maniac": 1
//		__DIR__"npc/venomsnake": 2
	]) );
	set("outdoors", "oldpine");

	setup();
	replace_program(ROOM);
}
