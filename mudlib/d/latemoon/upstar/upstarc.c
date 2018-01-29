
#include <room.h>
inherit ROOM;

void create()
{
     set("short", "前堂樓");
	set("long", @LONG
這裏是莊院二樓的前堂樓，有著傳統的古式建築風格。由上好的        
檜木搭建而成, 東面一陣耀眼的的白光由兩扇敞開的落地窗口射進來
，泛映出一種清新幽靜的格局。開了樓門出去可以一覽莊院內外的山
川景色，欣賞其美麗景觀。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
    "east" :__DIR__"uplook",
    "north" :__DIR__"upstar4",
    "south" :__DIR__"upstar3",

]));

    create_door("east","樓門","west", DOOR_CLOSED);
    setup();
	replace_program(ROOM);
}
