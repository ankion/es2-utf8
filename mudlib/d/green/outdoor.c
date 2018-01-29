#include <room.h>

inherit ROOM;

void create()
{
	set("short","石室");
	set("long",@LONG
這是一間石室，室內透着一種說不清的神祕力量，西邊有兩張石椅
東首牆上掛這一把木劍。北邊通往大廳，但牆上寫了兩行字，走近仔細
辨認，是：非我弟子，莫入此門。
LONG
);
	set("exits",([
	"enter" :__DIR__"cavehall",
	"south" :__DIR__"entrance",
	]) );
	create_door("south","大石門","north",DOOR_CLOSED);
	setup();
}

int valid_leave(object me,string dir)
{
	if ( dir == "enter" && me->query("family/master_id") != "master outer" )
		return notify_fail("入口被魔法封住了！\n");
	return ::valid_leave(me,dir);
}

