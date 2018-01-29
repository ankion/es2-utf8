// Room: /d/wiz/hall1.c

inherit ROOM;

void create()
{
	set("short", "巫師交誼廳");
	set("long", @LONG
這裏是巫師聊天討論的地方，如果巫師們要開會的話，也多半會選在這
裏舉行，往東是巫師會客室。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : "/d/wiz/jobroom",
  "east" : "/d/wiz/entrance",
]));
	set("no_clean_up", 0);

	setup();
	call_other("/obj/board/wizard_b", "???");
	replace_program(ROOM);
}
