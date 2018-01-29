// Room: /d/oldpine/tree1.c

inherit ROOM;

void create()
{
	set("short", "大松樹上");
	set("long", @LONG
你現在正攀附在一株大松樹的樹幹上，從這裏可以很清楚地望見樹
下的一切動靜，而不被人發覺，似乎是個幹偷雞摸狗勾當的好地方。
LONG
	);
	set("objects", ([
		"/d/oldpine/npc/spy":1 ]) );

	set("exits", ([ /* sizeof() == 2 */
  "up" : "/d/oldpine/tree2",
  "down" : "/d/oldpine/clearing",
]));

	setup();
	replace_program(ROOM);
}
