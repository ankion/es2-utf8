// Room: /u/k/karrimor/temple/corridor4.c

inherit ROOM;

void create()
{
	set("short", "迴廊");
	set("long", @LONG
你正站在迴廊轉角的地方, 迴廊從這往東邊及南邊而去。在北邊
是一間大房子, 裏面傳來陣陣叱喝的聲音。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
     "north" : __DIR__"trainroom",
     "south" : __DIR__"corridor6",
     "east" : __DIR__"corridor5",
]));

    create_door("north", "木門", "south");
	setup();
}
