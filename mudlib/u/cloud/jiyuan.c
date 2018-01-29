// jiyuan.c

#include <room.h>

inherit ROOM;

string look_sign(object me);

void create()
{
        set("short", "怡紅院");
        set("long", @LONG
你現在正站在怡紅院裏
    靠近門口的地方有一塊烏木雕成的招牌(sign)。
LONG
        );
        set("exits", ([
                "south"  : "/u/cloud/eroad1", 
                "up"  : "/u/cloud/jiyuan2",
        ]) );

        set("objects", ([
                "/u/cloud/npc/mother" : 1,
        ]) );

        set("item_desc", ([
                "sign": (: look_sign :),
        ]) );

        setup();

}

string look_sign(object me)
{
        return "招牌寫著：怡紅院\n";
}

