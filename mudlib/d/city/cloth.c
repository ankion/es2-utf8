// cloth.c
#include <ansi.h>
#include <room.h>
inherit ROOM;

string look_sign(object me);

void create()
{
        set("short", "四喜綢緞莊");
        set("long", @LONG
四喜綢緞莊是京師中的一家剛剛開業的專營衣帽的商店。店內
顧客稀少，顯得店鋪空蕩蕩的。櫃檯上凌亂地攤着幾匹綢緞。綢緞
莊的老闆出去進貨了，只有老闆娘空守店鋪。據說這家店鋪很有來
歷。一般的地痞也很少到店中鬧事。
    店堂上掛有一塊嶄新的招牌(sign)。
LONG
        );
        set("exits", ([
                "east"   :  __DIR__"street6" ]) );

        set("objects", ([
              __DIR__"npc/clother.c" : 1, ]) );

        set("item_desc", ([
                "sign": (: look_sign :),]) );

        setup();

}

string look_sign(object me)
{
        return RED"匾上三個大字：闖名堂\n"NOR;
}

