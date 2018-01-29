// biaoju.c

#include <room.h>

inherit ROOM;

string look_sign(object me);

void create()
{
        set("short", "鏢局");
        set("long", @LONG
你現在正站在鏢局裏。靠近門口的地方有一塊烏木雕成的招牌(sign)。
LONG
        );
        set("exits", ([
                "north" : __DIR__"eroad2" ]) );

        set("objects", ([
                "/u/cloud/npc/b_header" : 1,
                "/u/cloud/npc/bfighter" : 1,
        ]) );

        set("item_desc", ([
                "sign": (: look_sign :),
        ]) );
	set("valid_startroom", 1);
        setup();

}

string look_sign(object me)
{
        return "招牌寫著：鏢。\n";
}

