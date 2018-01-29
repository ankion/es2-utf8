#include <room.h>
inherit ROOM;

void create()
{
        set("short", "臥室");
        set("long", @LONG
這是淳于堡主起居的地方。東面的樓梯向下通向黑松閣東廳，
西面的樓梯向下通向黑松閣西廳。北面是一個小小的陽臺。西面則
是堡主的膳房。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
        "north" : __DIR__"yiantai",
          "south" : __DIR__"kitchen",
            "westdown" : __DIR__"west_blackge",
              "eastdown" : __DIR__"east_blackge",
]));
        create_door("south", "玉簾門", "north", DOOR_CLOSED);
        
        setup();
        
}
                              