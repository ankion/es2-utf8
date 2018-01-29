// zaihuoy.c

#include <room.h>

inherit ROOM;

string look_sign(object me);

void create()
{
        set("short", "雜貨鋪");
	set("long", @LONG
你現在正站在雜貨鋪裏
    靠近門口的地方有一塊烏木雕成的招牌(sign)。
LONG
        );
        set("exits", ([
		"north"		: "/u/cloud/nwroad3",
                "east"          : "/u/cloud/nroad2" ]) );

	set("objects", ([
                "/u/cloud/npc/seller" : 1,
 ]) );

        set("item_desc", ([
                "sign": (: look_sign :)
        ]) );

        setup();

}

string look_sign(object me)
{
        return "招牌寫著：商。\n";
}

