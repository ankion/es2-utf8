#include <weapon.h>

inherit BLADE;

void create()
{
        set_name("胡刀", ({ "hu-blade" }) );
        set_weight(6500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "這是一把彎如月牙兒的胡刀");
                set("value", 2000);
                set("material", "steel");
        }
        init_blade(30);

        set("wield_msg", "$N從腰間抽出一把亮閃閃的$n握在手中。\n");
        set("unwield_msg", "$N將手中的$n別在腰間。\n");


        setup();
}
