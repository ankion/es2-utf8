// duoqing_blade.c
#include <ansi.h>
#include <weapon.h>
inherit BLADE;

void create()
{
        set_name( RED "多情刀" NOR, ({ "duoqing blade", "blade" }) );
        set_weight(12000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long",
                    "這是一把耀眼的利刃。\n");

                set("value", 20000);
                set("material", "steel");
                set("wield_msg",
                    "只見白光一現，$N的手中已經多了一把$n。\n");
                set("unequip_msg", "$N將手中的$n插入身後的刀鞘。\n");
        }
        init_blade(35);
        setup();
}

