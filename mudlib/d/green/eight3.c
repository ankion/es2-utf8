#include <room.h>

inherit ROOM;

void create()
{
	set("short", "迷陣");
	set("long", @LONG
從這裏向四周望去，只見寒風陣陣，奇寒澈骨，如入北極風洞，四周
似乎罩着一層神密的薄霧，風吹不散，漸漸地遠處的景色模糊起來，你
覺得自己正深處一個飄忽的所在。你一回身，看見有一個路牌(sign)樹
在那裏。
LONG
);
	set("exits", ([ /* sizeof() == 4 */
	  "south" : __DIR__"eight3",
	  "north" : __DIR__"closed"  ,
	  "west"  : __DIR__"eight2"  ,
	  "east"  : __DIR__"eight4"  ,
	]));

	set("item_desc",([/* sizeof() == 1 */
	"sign" : "路牌上寫着：  巽--"
		 "巽爲風，遇青龍而生，遇玄武而死，"
		 "遇白虎而涉，遇朱雀而困。\n"
	])
	);
	
	set("outdoors","green");
	set("no_clean_up",0);
	setup();
	replace_program(ROOM);
}


