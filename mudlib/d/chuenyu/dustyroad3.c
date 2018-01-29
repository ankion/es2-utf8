// Room: /d/chuenyu/dustyroad2.c

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "青石小路");
        set("long", @LONG
這是一條通向一所民宅的青石小路。小屋就在你的東北方向。一個
整潔的小草坪在你的東邊。西南方向是一個三叉路口，你似乎可以聽到
賣花姑娘清脆的叫賣聲。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
        "southwest" : __DIR__"croad2",
          "northeast" : __DIR__"home",
            "north" : __DIR__"sunnyroad",
]));
        create_door("northeast", "木門", "southwest", DOOR_CLOSED);
        
        set("outdoors", "chuenyu");
        setup();
        replace_program(ROOM);
}

                            
