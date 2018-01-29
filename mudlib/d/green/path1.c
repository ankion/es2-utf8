// Room: /d/green/path1.c

inherit ROOM;

void create()
{
	set("short", "小路");
	set("long", @LONG
一條看來相當荒涼的小路, 兩旁雜草叢生, 好像很久都沒有人來過
的樣子. 往南很遠的地方可以看到村子的入口, 往北的路似乎不是很明
顯.
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : "/d/green/path0",
  "south" : "/d/green/path2",
]));
	set("outdoors", "green");

	setup();
	replace_program(ROOM);
}
