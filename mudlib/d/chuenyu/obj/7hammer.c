// sixhammer.c

#include <weapon.h>

inherit HAMMER;

void create()
{
        set_name("七星錘", ({ "sevenhammer" }) );
        set_weight(7000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "這是一把七星鐵錘，沉甸甸的。\n");
                set("value", 600);
                set("material", "steel");
                set("wield_msg", "$N拿出一把$n，試了試重量，然後握在手中。\n");
                set("unwield_msg", "$N放下手中的$n。\n");
        }

        init_hammer(15);
        setup();
}
