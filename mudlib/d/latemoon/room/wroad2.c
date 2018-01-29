#include <room.h>
inherit ROOM;

void create()
{
   set("short", "西廂房走道");
	set("long", @LONG
你走在西廂房走道上。長長的走道中，純金成的長燈架上掛了一排
飾麗的宮燈! 走道兩旁擺設了許多奇花異草，空氣中瀰漫一種淡淡的香
氣。在一柱柱雕飾華麗的長柱，刻畫許多彩繪的圖形，美不勝收。西面
你看到一扇門。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
   "north" :__DIR__"wroad1",
   "east" :__DIR__"corridor7",
   "west" :__DIR__"westroom",
   "southup" : "/d/latemoon/upstar/upstar2",

]));

   create_door("west","雕飾廂門","east", DOOR_CLOSED);
	setup();
	replace_program(ROOM);
}
