inherit ROOM;

void create()
{
   set("short", "甬路");
	set("long", @LONG
你走在石子墁的花園甬路上，只見兩邊翠竹夾路，土地下蒼苔
佈滿，往東北你看到鳳尾森森，龍吟細細，通往暖香榭。南面則是
一個小門。西方通往園中小橋。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
       "northwest" :__DIR__"bridge2",
       "northeast" :__DIR__"moon4",
       "south" :__DIR__"moondoor",

]));

	setup();
	replace_program(ROOM);
}
