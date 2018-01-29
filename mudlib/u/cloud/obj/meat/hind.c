// hind.c

#include <weapon.h>

inherit HAMMER;
inherit F_FOOD;

void create()
{
        set_name("牛腿", ({ "hind" }) );
        set_weight(800);
	set("long", "哇! 好香的牛腿! 不吃還等什麼?\n");
	set("unit", "只");
	set("value", 150);
        set("food_remaining", 5);
	set("food_supply", 80);
        set("material", "rib");
        set("wield_msg", "$N抓起一隻$n，握在手中當武器。\n");
        init_hammer(5);
        setup();
}

int finish_eat()
{
        set_name("牛腿骨", ({ "rib" }) );
        set_weight(300);
        set("long", "啃得精光的牛腿。\n");
        return 1;
}

	
