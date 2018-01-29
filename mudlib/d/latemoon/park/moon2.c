inherit ROOM;

void create()
{
   set("short", "湘園小徑");
	set("long", @LONG
湘園的桂花小徑是以不同顏色的細石砌成各種圖案。路面的
圖案組成，全員是一個整體。但每幅圖案又有獨立的內容，總計
花石子路上約有二百幅。沿路觀賞，美不勝收。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
       "south" :__DIR__"moon5",
       "east" :__DIR__"moonc",

]));

	setup();
	replace_program(ROOM);
}
