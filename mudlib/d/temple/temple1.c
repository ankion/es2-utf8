// Room: /u/k/karrimor/temple/temple1.c

#include <room.h>

inherit ROOM;

void create()
{
	set("short", "靈心觀大殿");
	set("long", @LONG
你現在來到靈心觀的大殿, 在你的眼前是一尊真武大帝的金身。
在金身的下方是一張硃紅色的大供桌, 上面排滿了鮮花素果。在桌子
的前方則擺放著三四個蒲團。東西兩側的圓形拱門通往連接後殿的回
廊。走過南邊的紅漆木門就是廣場。
LONG
	);

	set("item_desc", ([
		"door": (: this_object(), ({"look_door", "south"}) :),
	]) );
	set("exits", ([ /* sizeof() == 3 */
		"west" : __DIR__"corridor2",
		"south" : __DIR__"square",
		"east" : __DIR__"corridor1",
	]));

	set("valid_startroom", 1);
	set("objects", ([
		CLASS_D("taoist") + "/taolord" :1,
		__DIR__"npc/trainer"  :1,
		__DIR__"npc/tfighter" :1,
	 ]) );
	
	setup();

	// To cause the taoist's board to be loaded.
	call_other("/obj/board/taoist_b", "???");

    create_door("south", "紅漆木門", "north");

//	replace_program(ROOM);
}
