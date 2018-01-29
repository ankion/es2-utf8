// Room: /d/green/path5.c

inherit ROOM;

void create()
{
	set("short", "石板路");
	set("long", @LONG
這是一條平整的石板路, 上面隱約可以看見兩道很深的車輪, 看來
是用來作運輸用途的道路. 往北是一條較小的碎石路通往村內. 東邊有
一棟石屋, 旁邊的空地堆了一些石料. 南邊看去是一片矮樹叢. 石板路
往西邊延伸.
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : "/d/green/path6",
  "north" : "/d/green/path4",
  "east" : "/d/green/station0",
]));
	set("outdoors", "green");

	setup();
	replace_program(ROOM);
}
