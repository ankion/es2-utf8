
#include <armor.h>
inherit NECK;

void create()
{
        set_name( "黃金令牌" , ({ "gold ream","ream" }) );
         set("long", "一個閃閃發亮的黃金令牌，上有一些圖騰標誌。\n");
        set_weight(300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "個");
                set("value", 3000);
                set("no_drop", 1);
                set("material", "gold");
                set("armor_prop/unarmed", 1);
                set("armor_prop/dodge", 1);
        set("wear_msg", "$N將$n拿出戴在頸子上。\n");
        }
        setup();
}
