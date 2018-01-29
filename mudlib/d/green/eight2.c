#include <room.h>

inherit ROOM;

void create()
{
	set("short", "迷陣");
	set("long", @LONG
從這裏向四周望去，只見四面環水，只有腳下一點陸地，水面上
似乎罩着一層神密的薄霧，漸漸地遠處的景色模糊起來，你覺得
自己正深處一個飄忽的所在。你一回身，看見有一個路牌(sign)樹
在那裏。
LONG
);
	set("exits", ([ /* sizeof() == 4 */
	  "south" : __DIR__"eight2",
	  "north" : __DIR__"eight1"  ,
	  "west"  : __DIR__"eight3"  ,
	  "east"  : __DIR__"closed"  ,
	]));

	set("item_desc",([/* sizeof() == 1 */
	"sign" : "路牌上寫着：  坎--"
		 "坎爲水，遇青龍而死，遇玄武而涉，"
		 "遇白虎而生，遇朱雀而困。\n"
	])
	);
	
	set("outdoors","green");
	set("no_clean_up",0);
	setup();
	replace_program(ROOM);
}


