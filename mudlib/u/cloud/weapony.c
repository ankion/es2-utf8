// weapony.c

#include <room.h>

inherit ROOM;

string look_sign(object me);

void create()
{
        set("short", "兵器屋");
        set("long", @LONG
你現在正站在兵器屋裏
    靠近門口的地方有一塊烏木雕成的招牌(sign)。
LONG
        );
        set("exits", ([
                "west"          : "/u/cloud/nroad1" ]) );

        set("objects", ([
                "/u/cloud/npc/weaponor" : 1,
 ]) );

        set("item_desc", ([
                "sign": (: look_sign :),
        ]) );

        setup();

}

string look_sign(object me)
{
        return "招牌寫著：專賣各式兵器\n";
}

