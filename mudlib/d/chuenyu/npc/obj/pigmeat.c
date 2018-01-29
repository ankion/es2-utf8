#include <weapon.h>
inherit HAMMER;
inherit F_FOOD;

void create()
{
        set_name("烤山豬肉", ({ "pork" }) );
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "哇! 好香的烤山豬肉! 不吃還等什麼?\n");
                set("unit", "斤");
                set("value", 60);
                set("food_remaining", 6);
                set("food_supply", 90);
                set("material", "rib");
        }
        init_hammer(4);
        setup();
}

int finish_eat()
{
        set_name("山豬骨頭", ({ "rib" }) );
        set_weight(250);
        set("long", "啃得精光的山豬骨頭。\n");
        return 1;
}
