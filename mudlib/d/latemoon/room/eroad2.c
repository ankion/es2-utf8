inherit ROOM;

void create()
{
   set("short", "東廂房走道");
	set("long", @LONG
通過後廳走道，接著你走進東廂房走道。除了長長的走道中，
一排飾麗的宮燈! 走道兩旁擺設了許多奇花異草，各有各的特色與
形態，空氣中瀰漫一種淡淡的香氣。往南通往東廂房。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
    "north" :__DIR__"lroad1",
    "south" :__DIR__"eroad1",

]));

	setup();
	replace_program(ROOM);
}
