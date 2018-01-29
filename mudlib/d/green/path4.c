// Room: /d/green/path4.c

inherit ROOM;

void create()
{
	set("short", "小路");
	set("long", @LONG
你走在一條不算寬的碎石路上, 往北是一個交叉路口. 東邊有一棟
木造建築, 看來相當的破舊, 一片快要散掉似的木牌懸掛在門口, 上面
的字跡已經不是很清楚了. 往南過去是一條鋪著石板的大路.
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : "/d/green/path5",
  "north" : "/d/green/path3",
  "east" : "/d/green/shop0",
]));
	set("outdoors", "green");

	setup();
	replace_program(ROOM);
}
