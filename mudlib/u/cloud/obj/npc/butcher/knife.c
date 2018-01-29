// knife.c

#include <weapon.h>

inherit DAGGER;

void create()
{
        set_name("解牛刀", ({ "knife" }) );
        set_weight(1500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "這是一把很鋒利的鋼刀, 就是短了些。\n");
                set("value", 200);
                set("material", "steel");
        }
        init_dagger(10);

        set("wield_msg", "$N從腰間抽出一把亮閃閃的$n握在手中。\n");
        set("unwield_msg", "$N將手中的$n別在腰間。\n");

// The setup() is required.

        setup();
}

