// Room: /d/oldpine/spath1.c

inherit ROOM;

void create()
{
	set("short", "林間小路");
	set("long", @LONG
你現在正走在一片松樹林中的小路上，小路往北通往一處空地，一
株巨大無朋的松樹矗立在空地中央，小路往南是一條長長的下坡道，這
條路上足跡很多，顯然常有人經過。
LONG
	);
	set("objects", ([ /* sizeof() == 3 */
//  __DIR__"npc/tall_bandit" : 1,
//  __DIR__"npc/fat_bandit" : 1,
  __DIR__"npc/bandit" : 3,
]));
	set("outdoors", "oldpine");
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"clearing",
  "north" : __DIR__"spath2",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
