// Room: /d/canyon/stone_forest3.c

inherit ROOM;

void create()
{
	set("short", "夢幻迷境入口");
	set("long", @LONG
天光點著，華光亮，大概就是這樣的一個情形吧，穿過了黃石穿
林路，一束極大的光注猛然照射到你的身上，猶如沐於春風，心情爽
朗極了，但面對北側奇特的鏡子居然有種令人不可抗拒的壓力，在這
尺尺地方，鏡面反射日光，強照黃石穿林路，想到這讓你有種莫名的
恐懼，在莫名中被吸引而來的恐懼，進入或離開，生死一瞬間。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"mirror" : __DIR__"fantasy1",
		"east" : __DIR__"stone_forest2",
]));

	setup();
	replace_program(ROOM);
}
