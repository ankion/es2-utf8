// Room: /d/green/path6.c

inherit ROOM;

void create()
{
	set("short", "石板路");
	set("long", @LONG
這是一條平整的石板路, 上面隱約可以看見兩道很深的車輪, 看來
是用來作運輸用途的道路. 往西是通往山下的路, 往東你可以看到一些
建築物, 像是村莊之類的. 南邊看去是一片矮樹叢.
LONG
);
	set("exits", ([ /* sizeof() == 2 */
  "west" : "/d/snow/crossroad",
  "east" : "/d/green/path5",
]));
	set("no_clean_up", 0);
	set("outdoors", "green");

	setup();
	replace_program(ROOM);
}
