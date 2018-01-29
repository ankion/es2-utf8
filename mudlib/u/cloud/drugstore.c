// drugstore.c

#include <room.h>

inherit ROOM;

string look_sign(object me);

void create()
{
        set("short", "藥店");
	set("long", @LONG
你現在正站在藥店裏
    靠近門口的地方有一塊烏木雕成的招牌(sign)。
LONG
        );
        set("exits", ([
                "south"          : "/u/cloud/nroad1" ]) );

        set("objects", ([
		"/u/cloud/npc/doctor" : 1,
	]) );

        set("no_fight","1");
        set("item_desc", ([
                "sign": (: look_sign :),
        ]) );

        setup();

}

string look_sign(object me)
{
        return "招牌寫著：藥。\n";
}

