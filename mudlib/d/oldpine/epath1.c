// Room: /d/oldpine/epath1.c

inherit ROOM;

void create()
{
	set("short", "林間小路");
	set("long", @LONG
你現在正走在一條松樹林中的小路，這裏的松樹樹幹上都有著一些
奇怪的記號，像是被人用刀子劃過，小路的西邊是一塊空地，往東不遠
可以看到一條山澗，上面橫跨著一座小石橋。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : "/d/oldpine/clearing",
  "east" : "/d/oldpine/epath2",
]));
	set("outdoors", "oldpine");

	setup();
	replace_program(ROOM);
}
