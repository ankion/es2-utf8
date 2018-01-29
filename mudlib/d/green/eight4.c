#include <room.h>

inherit ROOM;

void create()
{
	set("short", "迷陣");
	set("long", @LONG
從這裏向四周望去，只見鉛雲低沉，忽然一道閃電，跟着一陣巨雷，
遠山爲之迴響，身旁似乎罩着一層神密的薄霧，漸漸地遠處的景色
模糊起來，你覺得自己正深處一個飄忽的所在。你一回身，看見有
一個路牌(sign)樹在那裏。
LONG
);
	set("exits", ([ /* sizeof() == 4 */
	  "south" : __DIR__"closed",
	  "north" : __DIR__"eight5"  ,
	  "west"  : __DIR__"eight4"  ,
	  "east"  : __DIR__"eight3"  ,
	]));

	set("item_desc",([/* sizeof() == 1 */
	"sign" : "路牌上寫着：  震--"
		 "震爲雷，遇青龍而涉，遇玄武而生，"
		 "遇白虎而困，遇朱雀而死。\n"
	])
	);
	
	set("outdoors","green");
	set("no_clean_up",0);
	setup();
	replace_program(ROOM);
}


