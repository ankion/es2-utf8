// Room: /d/green/path3.c

inherit ROOM;

void create()
{
	set("short", "三叉路口");
	set("long", @LONG
你來到一條三叉路口, 往東看去是另一條更小更窄的黃土路, 主要
道路是南北向的, 西邊有一棟民宅.
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "north" : "/d/green/path2",
  "south" : "/d/green/path4",
  "west" : "/d/green/house0",
  "east" : "/d/green/path8",
]));
	set("outdoors", "green");

	setup();
	replace_program(ROOM);
}
