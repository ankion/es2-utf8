// butchery.c

#include <room.h>

inherit ROOM;

string look_sign(object me);

void create()
{
        set("short", "鎮北肉鋪");
	set("long", @LONG
你現在正站在鎮北肉鋪裏，肉架上掛滿了血淋淋的生肉，一股腥
氣撲面而來，不時有幾隻蒼蠅在屋裏飛來飛去。
    靠近門口的地方有一塊牛骨雕成的招牌(sign)，上面寫着些
什麼。
LONG
        );

        set("item_desc", ([
                "sign": (: look_sign :),
        ]) );

        set("exits", ([
                "east"          : "/u/cloud/nwroad1" ]) );

        set("objects", ([
                "/u/cloud/npc/butcher" : 1,
		"/u/cloud/npc/fly.c" : 6,
 ]) );

        setup();

}

string look_sign(object me)
{
        return (@LONG
本店即將收購死狗。
LONG);
}

