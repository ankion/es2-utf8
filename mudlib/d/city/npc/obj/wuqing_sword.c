// wuqing_sword.c"
#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
    set_name( HIW"無情劍" NOR,({"cool sword","sword"}));
        set_weight(4500);
        if( clonep() )
                set_default_object(__FILE__);
        else{
                set("unit", "把");
        set("long", "劍鋒寒氣逼人，劍身發出異樣的青光。\n");
                set("value", 24000);
                set("material", "異類金屬");
        set("wield_msg", "$N「唰」地一聲抽出一把寒氣逼人的$n握在手中。\n");
        set("unwield_msg", "$N將手中的$n插入腰間的劍鞘。\n");
        set("replica_ob", "/obj/weapon/longsword");
    }
        init_sword(45);
        setup();
}

