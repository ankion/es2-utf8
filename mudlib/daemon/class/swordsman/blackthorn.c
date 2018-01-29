// blackthorn.c

#include <weapon.h>

inherit SWORD;

void create()
{
        set_name("玄蘇劍", ({ "blackthorn sword", "blackthorn", "sword" }) );
        set_weight(15000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long",
                        
"這是一把通體黝黑的重劍，上面生滿了尖銳的倒鉤，乃是喬陰柳家\n"
                        
"歷代相傳的寶劍，據說這把劍殺人不沾血，永遠保持殺氣。\n");
                set("value", 2400);
                set("material", "blacksteel");
                set("wield_msg", 
"只聽見「颼」地一聲，$N的手中已經多了一把寒光四射的寶劍——$n。\n");
                set("unequip_msg", "$N將手中的$n插入腰間的劍鞘。\n");
        }
        init_sword(58);
        setup();
}
 
