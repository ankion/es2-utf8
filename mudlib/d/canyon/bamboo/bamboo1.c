// Room: /d/canyon/bamboo/bamboo1.c

inherit ROOM;

void create()
{
	set("short", "竹林道入口");
	set("long", @LONG
修長的竹子映滿眼廉，穹空無邊，風拂無形，芬芳的氣味隨著清
風而漂流著，真有如如沐春風，生機充滿的竹林道，讓站立其中的人
皆受其境界而霍然開朗，忘卻了江湖的險惡，行止於此，一直氣凝字
之跡，顯出居此主人之內力雄厚，亦使你想找點看到居此八泰之地的
主人是何等的人物。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"north" : __DIR__"bamboo2",
		"back" : "/d/canyon/fantasy1",
]));

	setup();
	replace_program(ROOM);
}
