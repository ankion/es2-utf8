// Room: /d/temple/ladder1.c

inherit ROOM;

void create()
{
	set("short", "石英岩石階");
	set("long", @LONG
長長的階梯也終將到了盡頭, 階梯的盡頭矗立著一座山門, 山門
上龍飛鳳舞地寫了三個字, 筆力蒼勁有力顯得氣勢非凡。山風吹來帶
著絲絲的寒意, 令你有股高處不勝寒的感覺。
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/little_taoist1" : 1,
]));
	set("outdoors", "temple");
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"entrance",
  "west" : __DIR__"ladder2",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
