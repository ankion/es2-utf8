#include <room.h>

inherit ROOM;

void create()
{
    set("short","禁閉房");
	set("long", @LONG
這裏四面都是單調的牆壁(wall)。通常莊內弟子犯錯就是
關在這兒！反省思過。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
      "east" :__DIR__"latemoon5",
]));

        set("item_desc", ([
                "wall": @TEXT
    你仔細觀看石牆，突然發現原本單調的牆上隱隱約約出現了
一幅渺渺茫茫，似有似無的景像。彷佛是幻境，但又似真實，你
清楚的看到一首詞：「夢裏消魂無說處，覺來惆悵消魂誤。」
TEXT
        ]) );

      set("objects", ([
         __DIR__"npc/funlin" : 1 ]) );
     create_door("east","銅門","west", DOOR_CLOSED);
	setup();
	replace_program(ROOM);
}
