#include <ansi.h>

#include <armor.h>

inherit WAIST;

void create()
{
        set_name( "腰帶" , ({ "belt" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "條");
                set("value", 700);
                set("material", "cloth");
                set("armor_prop/armor", 4);
                set("armor_prop/dodge", 1);
       set("wear_msg", "$N將$n拿出系在腰上。\n");
        }
   setup();
}
