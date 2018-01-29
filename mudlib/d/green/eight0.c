#include <room.h>

inherit ROOM;

void create()
{
	set("short", "迷陣");
	set("long", @LONG
從這裏向四周望去，只見一片無垠的綠野，然而地面上似乎
罩着一層神密的薄霧，漸漸地遠處的景色模糊起來，你覺得
自己正深處一個飄忽的所在。你一回身，看見有一個路牌(sign)
樹在那裏。
LONG
);
	set("exits", ([ /* sizeof() == 4 */
	  "south" : __DIR__"entrance",
	  "north" : __DIR__"closed"  ,
	  "west"  : __DIR__"eight0"  ,
	  "east"  : __DIR__"eight1"  ,
	]));

	set("item_desc",([/* sizeof() == 1 */
	"sign" : "路牌上寫着：  坤--"
		 "坤爲地，遇青龍而生，遇玄武而死，"
		 "遇白虎而困，遇朱雀而涉。\n"
	])
	);
	
	set("outdoors","green");
	set("no_clean_up",0);
	setup();
	replace_program(ROOM);
}


