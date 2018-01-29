#include <room.h>

inherit ROOM;

void create()
{
	set("short","石室大廳");
	set("long",@LONG
這就是傳說中的絕塵子的修行之所，北面是一座佛像，佛像頂部
有一顆夜明珠發出瑩瑩的光芒。室內設施古樸，但卻一塵不染。
LONG
);
	set("exits",([
	"south" :__DIR__"outdoor",
	]) );
        set("objects", ([
                CLASS_D("juechen")+"/master" : 1,
                ]) );

	set("valid_startroom", 1);
	setup();
	replace_program(ROOM);
}


