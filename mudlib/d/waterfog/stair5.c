// Room: /d/waterfog/stair5.c

inherit ROOM;

void create()
{
	set("short", "白石階梯");
	set("long", @LONG
你現在正走在一條長長的白石階梯上，階梯隨著山峯蜿蜒盤旋，宛
如一條白龍，水煙閣就矗立在北邊的山峯頂上，即使是從這麼近的距離
你仍然感覺這座樓閣飄飄渺渺，難以捉摸。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northup" : "/d/waterfog/frontyard",
  "eastdown" : "/d/waterfog/clifftop",
]));
	set("outdoors", "waterfog");

	setup();
	replace_program(ROOM);
}
