#include <room.h>

inherit ROOM;

void create()
{
	set("short", "迷陣");
	set("long", @LONG
從這裏向四周望去，只見火光沖天，熾熱難當，身旁似乎罩着一層
神密的薄霧，漸漸地遠處的景色模糊起來，你覺得自己正深處一個
飄忽的所在。你一回身，看見有一個路牌(sign)樹在那裏。
LONG
);
	set("exits", ([ /* sizeof() == 4 */
	  "south" : __DIR__"eight5",
	  "north" : __DIR__"eight4"  ,
	  "west"  : __DIR__"eight6"  ,
	  "east"  : __DIR__"closed"  ,
	]));

	set("item_desc",([/* sizeof() == 1 */
	"sign" : "路牌上寫着：  離--"
		 "離爲火，遇青龍而死，遇玄武而涉，"
		 "遇白虎而生，遇朱雀而困。\n"
	])
	);
	
	set("outdoors","green");
	set("no_clean_up",0);
	setup();
	replace_program(ROOM);
}


