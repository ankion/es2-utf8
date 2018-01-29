inherit ROOM;

void create()
{
   set("short", "西廂房走道");
	set("long", @LONG
通過後廳走道，接著你走進西廂房走道。長長的走道中，純金
成的長燈架上掛了一排飾麗的宮燈! 走道兩旁擺設了許多奇花異草，
空氣中瀰漫一種淡淡的香氣。在一柱柱雕飾華麗的長柱，刻畫許多
彩繪的圖形，美不勝收。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
    "north" :__DIR__"lroad3",
    "south" :__DIR__"wroad2",

]));

	setup();
	replace_program(ROOM);
}
