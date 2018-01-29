// tea_leaf.c

#include <weapon.h>

inherit THROWING;

void create()
{
        set_name("雞毛", ({ "feather" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","用來清除灰塵的雞毛\n");
                set("unit", "把");
                set("base_unit", "片");
                set("base_weight", 1);
                set("base_value", 1);
        }
        set_amount(30);
        init_throwing(1);
        setup();
}
