// moon_blade.c

#include <weapon.h>

inherit BLADE;

void create()
{
        set_name("霜月刀", ({ "moon blade", "blade" }) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long",
                        
"這是一把耀眼的利刃，刀背上面帶有道凹槽，乃是陳劍秋的成名武器。\n");
                        
                set("value", 1800);
                set("material", "steel");
                set("wield_msg", 
"只聽見「颼」地一聲，$N的手中已經多了一把$n。\n");
                set("unequip_msg", "$N將手中的$n插入腰間的劍鞘。\n");
        }
        init_blade(40);
        setup();
}
 
