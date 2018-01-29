// Room: /d/oldpine/tree2.c

inherit ROOM;

void create()
{
	set("short", "大松樹上");
	set("long", @LONG
你現在正攀附在一株大松樹的樹幹上，這裏離地面已經有七、八丈
高，如果不小心跌了下去，不斷條腿也得去半條命，松樹上結了許多球
果，不過大部分都離樹幹很遠，你構不到。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "up" : "/d/oldpine/tree3",
  "down" : "/d/oldpine/tree1",
]));

	set ("objects", ([
		__DIR__"npc/butterfly":		6,
]));

	setup();
	replace_program(ROOM);
}
