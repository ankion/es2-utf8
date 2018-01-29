#include <room.h>

inherit ROOM;

void create()
{
	set("short", "迷陣");
	set("long", @LONG
從這裏向四周望去，只見身處一個大湖泊之中，腳下只有四尺見方的
一塊陸地，湖上似乎罩着一層神密的薄霧，漸漸地遠處的景色模糊起來，
你覺得自己正深處一個飄忽的所在。你一回身，看見有一個路牌(sign)
樹在那裏。
LONG
);
	set("exits", ([ /* sizeof() == 4 */
	  "south" : __DIR__"eight5",
	  "north" : __DIR__"eight7"  ,
	  "west"  : __DIR__"closed"  ,
	  "east"  : __DIR__"eight6"  ,
	]));

	set("item_desc",([/* sizeof() == 1 */
	"sign" : "路牌上寫着：  兌--"
		 "兌爲澤，遇青龍而困，遇玄武而生，"
		 "遇白虎而死，遇朱雀而涉。\n"
	])
	);
	
	set("outdoors","green");
	set("no_clean_up",0);
	setup();
	replace_program(ROOM);
}


