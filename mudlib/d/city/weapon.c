// weapon.c
#include <room.h>
inherit ROOM;

string look_sign(object me);

void create()
{
        set("short", "京師武器店");
        set("long", @LONG
這裏是江湖中人人所向往的京師武器店。店鋪寬敞，紅磚鋪地。
四周的牆壁上掛滿了各式的刀劍。東邊的武器架上的槍戟的反光令
你睜不開眼。靠北牆的大櫃檯一塵不染，幾個夥計正在忙碌。
    靠近店門的地方有一塊金字招牌(sign)。
LONG
        );
        set("exits", ([
                "south"   :  __DIR__"street9" ]) );

        set("objects", ([
              __DIR__"npc/weaponor" : 1, ]) );
        
        set("item_desc", ([
                "sign": (: look_sign :),]) );

        setup();

}

string look_sign(object me)
{
        return "招牌寫著：京師武器店專營各式武器。\n";
}

