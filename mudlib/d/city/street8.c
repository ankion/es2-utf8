// Room: /d/city/street8.c

inherit ROOM;

void create()
{
	set("short", "京師街道");
	set("long", @LONG
你現在正走在京師的大街上，往東可以隱約看到城門銅釦上的反
光，在你的北邊是京城唯一的錢莊，往西有熙熙攘攘的人羣，偶爾還
能見到一倆個僧侶。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"street9",
  "north" : "/d/city/bank",
  "west" : "/d/city/street7",]));
	set("objects", ([
		"d/snow/npc/scavenger": 1 ]) );

	set("outdoors", "city");

	setup();
	replace_program(ROOM);
}
