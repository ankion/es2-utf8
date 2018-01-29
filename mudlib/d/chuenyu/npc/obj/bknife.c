// knife.c

#include <weapon.h>

inherit DAGGER;

void create()
{
        set_name("碧玉刀", ({ "knife" }) );
        set_weight(6500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "這是一把當年張家老祖宗退隱時皇上賜的寶刀");
                set("value", 20000);
                set("material", "crimsonsteel");
        }
        init_dagger(40);

        set("wield_msg", "$N從腰間抽出一把亮閃閃的$n握在手中。\n");
        set("unwield_msg", "$N將手中的$n別在腰間。\n");


        setup();
}

