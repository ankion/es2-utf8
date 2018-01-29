#include <weapon.h>

inherit BLADE;

void create()
{
        set_name("柳玉刀", ({ "blade","yu-blade" }) );
       set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("value", 500);
                set("material", "iron");
                set("long", "這是一柄纖細的柳玉刀，輕薄短小。\n");
                set("wield_msg", "$N抽出一柄纖細的$n握在手中。\n");
                set("unequip_msg", "$N將手中的$n插入腰間的刀鞘。\n");
        }
        init_blade(27);
        setup();
}
