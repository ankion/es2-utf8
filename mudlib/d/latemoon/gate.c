#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
	set("short", "晚月莊大門");
	set("long", @LONG
你來到了這個小徑的盡頭，一個有著硃紅漆大門大宅
院矗立在你的面前，門口掛著兩串燈籠(lantern),上面寫
得有字，像這樣一間豪華的大宅院出現在這樣的鄉間野外
，使你覺得有些突兀，大宅的南邊、東邊都是茂密的林子
，看來也沒有其他的路。
LONG
	);
	set("item_desc", ([
		"lantern" : "燈籠上幾個娟秀的字跡寫著：\n"
			BRED HIW "晚霞西照人影依稀 \n月影高掛和風婉約 \n" NOR
	]) );

	set("exits", ([
		"east"	:	__DIR__"entrance",
		"west" :		__DIR__"front_yard",
	]));
	
	create_door ("east", "拱門", "west", DOOR_CLOSED);
 
	set("outdoors", "latemoon");

	setup();
	replace_program(ROOM);
}
