// Room: /d/village/lordhouse2.c

inherit ROOM;

void create()
{
	set("short", "財主家東房");
	set("long", @LONG
東房內的北面擺放着很大的八仙桌，桌子的後面是供奉關公的神龕，
神龕上三根拇指粗細的香慢慢燃着，關公的手似乎指向前面的牆壁(wall)，
你還是第一次見到如此奇特姿勢的關公像。在牆角處放着一根鐵棍(stick)，
順着東側打開的窗子望出去，可以看到遠遠的官道上來來往往的人羣和遙
遠處陰森的黑松山。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"lordhouse1",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
