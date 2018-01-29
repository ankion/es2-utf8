#include <room.h>

inherit ROOM;

int DOOR_OPEN = 0;

void create()
{
	set("short","石室");
	set("long",@LONG
這是一間石室，西邊有一個大廳，大廳中有光線透出來，因此可以看清
石室中的東西，南邊有兩個蒲團，似是用來打坐的，此外別無他物。
LONG
);
	set("exits",([
	"west" :__DIR__"cavehall",
	"south":__DIR__"water",
	]) );
	create_door("south","密門","north",DOOR_CLOSED);
	setup();
}

