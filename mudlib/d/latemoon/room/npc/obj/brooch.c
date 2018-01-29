
#include <armor.h>
inherit NECK;

void create()
{
        set_name( "鑽石胸針", ({ "brooch diamond","brooch" }) );
        set("long","這是一個用鑽石鑲成的美麗胸飾。\n");
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "個");
                set("value", 1500);
                set("material", "gold");
                set("armor_prop/armor", 2);
        set("wear_msg", "$N將$n從袖袋中拿出別在胸前衣飾上。\n");
        }
        setup();
}
