inherit ROOM;

void create()
{
   set("short", "甬路");
	set("long", @LONG
桂花園的石子甬道是以不同顏色的細石砌成各種圖案。路面
的圖案組成，全員是一個整體。但每幅圖案又有獨立的內容，總
計花石子路上約有二百幅。沿路觀賞，美不勝收。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
       "southeast" :__DIR__"paroad2",
       "north" :__DIR__"moon5",
       "west" :__DIR__"moroom",

]));

	setup();
	replace_program(ROOM);
}
