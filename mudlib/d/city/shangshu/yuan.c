// /d/city/shangshu/yuan

#include <room.h>

inherit ROOM;

void create()
{
        set("short", "尚書府庭院");
        set("long",@LONG
你走到了尚書府的庭院。院子很大，地面規規整整地用清一色的
大青石鋪就，顯示出主人的氣派。東邊的府門時常關着，不是高官可
甭想進來。西向是主人會客的客廳。北行的石路通向客房，而向南則
是去往內院。
LONG
        );

        set("exits", ([
                "west" :        __DIR__"gate",
                "east" :        __DIR__"keting",
		"south":	__DIR__"road3",
		"north":	__DIR__"road2",
                ]));
       
	set("outdoors", "city");

        create_door ("west", "大鐵門", "east", DOOR_CLOSED);

        setup();
}

int valid_leave(object me,string dir)
{
        if ( (dir=="east" || dir == "west" )&&  !userp(this_player()))
        return 0;
        
	return ::valid_leave(me,dir);
}

