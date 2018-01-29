// pink_cloth.c
#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
        set_name(WHT"黑牡丹"NOR, ({ "black flower", "flower" }) );
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", WHT"清高冷傲的黑牡丹。\n"NOR);
                set("unit", "朵");
                set("value", 6);
                set("material", "plant");
                set("armor_prop/armor", 0);
                set("armor_prop/personality", 3);
                set("wear_msg", "$N輕輕地把一朵$n戴在頭上。\n");
                set("unwield_msg", "$N輕輕地把$n從頭上除了下來。\n");
                set("female_only", 1);

        }
        setup();
}

