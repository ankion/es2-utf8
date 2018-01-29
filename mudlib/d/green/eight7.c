#include <room.h>

inherit ROOM;

void create()
{
	set("short", "迷陣");
	set("long", @LONG
從這裏向四周望去，只見長天一碧，沃野千里，正自心曠神怡，
那層神密的薄霧又起，漸漸地遠處的景色模糊起來，你覺得自
己正深處一個飄忽的所在。你一回身，看見有一個路牌(sign)
樹在那裏。
LONG
);
	set("exits", ([ /* sizeof() == 4 */
	  "south" : __DIR__"stoneroom",
	  "north" : __DIR__"eight7"  ,
	  "west"  : __DIR__"eight6"  ,
	  "east"  : __DIR__"closed"  ,
	]));

	set("item_desc",([/* sizeof() == 1 */
	"sign" : "路牌上寫着：  乾--"
		 "乾爲天，遇青龍而死，遇玄武而困，"
		 "遇白虎而涉，遇朱雀而生。\n"
	])
	);
	
	set("outdoors","green");
	set("no_clean_up",0);
	setup();
}

int valid_leave(object me,string dir)
{
	if ( dir == "south" )
		me->set("八卦陣",1);
	return ::valid_leave(me,dir);
}

