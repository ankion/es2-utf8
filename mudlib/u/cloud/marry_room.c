// marry_room.c

#include <room.h>

inherit ROOM;

string look_sign(object me);

void create()
{
        set("short", "紅娘莊");
        set("long", @LONG
你現在正站在紅娘莊裏，這裏是專門替人締結婚約和解除婚約的地方，
鎮裏所有的夫婦都是在這裏喜結良緣的，就連附近鎮子也有許多慕名
而來的。靠近門口的地方有一塊烏木雕成的招牌(sign)。
LONG
        );
        set("exits", ([
                "south": __DIR__"wroad0", 
         ]) );

        set("item_desc", ([
                "sign": (: look_sign :),
        ]) );

        set("objects", ([
                "/u/cloud/npc/mei_po" : 1,
        ]) );
 
        setup();

}

string look_sign(object me)
{
        return "締結或解除婚約。\n";
}

