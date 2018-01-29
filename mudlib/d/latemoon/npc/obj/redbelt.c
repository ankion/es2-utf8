#include <ansi.h>

#include <armor.h>
inherit WAIST;

void create()
{                              
     set_name(HIG "碧玉"+ HIM "紅裎帶" NOR, ({"Red belt","belt"}) );
     set_weight(500);
     if ( clonep() )
              set_default_object(__FILE__);
     else {
     set("long", "這是一條絲綢制的綵帶，質感佳，上繡有彩□江水紋。\n");
            set("unit", "條");
            set("value", 2000);
            set("material", "cloth");
            set("armor_prop/armor", 4);
     set("wear_msg", "$N將$n拿出系在腰上。\n");
    }
    setup();
}
