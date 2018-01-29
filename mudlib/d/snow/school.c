// Room: /d/snow/school.c

inherit ROOM;

void create()
{
	set("short", "書院");
	set("long", @LONG
這裏是一間寬敞的書院，雖然房子看起來很老舊了，但是打掃得很
整潔。牆壁上掛著一幅山水畫，意境頗爲不俗。書院的大門開在北邊，
西邊有一扇木門通往邊廂。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
    "north" : __DIR__"sroad2",
  ]));

	set("objects", ([
		__DIR__"npc/teacher": 1 
	]) );
	setup();
	replace_program(ROOM);
}
