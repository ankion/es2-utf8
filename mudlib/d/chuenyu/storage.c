#include <room.h>
inherit ROOM;

void create()
{
        set("short", "儲藏室");
        set("long", @LONG
一個小小的儲藏室。四壁上佈滿了灰塵。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
        "north" : __DIR__"west_blackge",
        ]));
        set("objects", ([
        "/obj/longsword" : 5,
        ]) );
        
        create_door("north", "木門", "south", DOOR_CLOSED);
        setup();
}

                