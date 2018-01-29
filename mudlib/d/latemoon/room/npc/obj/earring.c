
#include <armor.h>
inherit HEAD;

void create()
{
        set_name( "耳環", ({ "earring" }) );
        set("long","這是一串用寶石鑲串成的閃亮耳環。\n");
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "串");
                set("value", 1500);
                set("material", "gold");
                set("armor_prop/armor", 1);
        set("wear_msg", "$N將$n拿出穿戴在耳朵上。\n");
        }
        setup();
}
