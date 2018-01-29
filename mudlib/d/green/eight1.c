#include <room.h>

inherit ROOM;

void create()
{
	set("short", "迷陣");
	set("long", @LONG
從這裏向四周望去，只見羣山環繞，不知所處，地面上似乎
罩着一層神密的薄霧，漸漸地遠處的景色模糊起來，你覺得
自己正深處一個飄忽的所在。你一回身，看見有一個路牌(sign)樹
在那裏。
LONG
);
	set("exits", ([ /* sizeof() == 4 */
	  "south" : __DIR__"eight1",
	  "north" : __DIR__"eight2"  ,
	  "west"  : __DIR__"closed"  ,
	  "east"  : __DIR__"eight0"  ,
	]));

	set("item_desc",([/* sizeof() == 1 */
	"sign" : "路牌上寫着：  艮--"
		 "艮爲山，遇青龍而涉，遇玄武而生，"
		 "遇白虎而死，遇朱雀而困。\n"
	])
	);
	
	set("outdoors","green");
	set("no_clean_up",0);
	setup();
	replace_program(ROOM);
}


