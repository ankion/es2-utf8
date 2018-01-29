// Room: /d/temple/ladder2.c

inherit ROOM;

void create()
{
	set("short", "石英岩石階");
	set("long", @LONG
你正走在一道長長的石英岩階梯上, 階梯的兩側種植著一排高聳
的松樹。擡頭望望東北邊那座高聳挺拔的山峯, 在雲霧飄渺的山頂上
, 矗立著一座雄偉的白色樓閣。
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/guest" : 1,
]));
	set("outdoors", "temple");
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"ladder1",
  "southdown" : __DIR__"ladder3",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
