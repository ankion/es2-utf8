// Room: /u/cloud/m_house.c

inherit ROOM;

void create()
{
	set("short", "張百萬家");
	set("long", @LONG
這裏是張百萬的府宅，常人可進不來
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"rich",
]));
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/millinare" : 1,
  __DIR__"npc/jiading" : 2,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
