// bookstore.c

#include <room.h>

inherit ROOM;

string look_sign(object me);

void create()
{
        set("short", "書局");
	set("long", @LONG
你現在正站在書局裏
    靠近門口的地方有一塊烏木雕成的招牌(sign)。
LONG
        );
        set("exits", ([
                "north"          : "/u/cloud/wroad1" ]) );

        set ("objects", ([
	"/u/cloud/npc/book_seller" : 1,  	
	]));
	
	set("item_desc", ([
                "sign": (: look_sign :),
        ]) );

        setup();

}

string look_sign(object me)
{
        return "招牌寫著：書。\n";
}

