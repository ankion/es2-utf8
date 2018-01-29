// Room: /d/green/path2.c

inherit ROOM;

void create()
{
	set("short", "三叉路口");
	set("long", @LONG
小路到了這裏往北就算是出了村子. 西邊有一間小小的土地廟, 東
邊是一棟民宅似的建築, 不過入口不在這邊. 往南是一個交叉路口.
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : "/d/green/path3",
  "north" : "/d/green/path1",
  "west" : "/d/green/temple0",
]));
	set("outdoors", "green");
	set("objects", ([
	"/d/green/npc/kid2" : 2,
	]) );

	setup();
	replace_program(ROOM);
}
