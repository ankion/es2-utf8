// chicken_leg.c

#include <weapon.h>

inherit HAMMER;
inherit F_FOOD;

void create()
{
	set_name("烤雞腿", ({ "chicken leg", "chicken", "leg" }) );
	set_weight(350);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一枝烤得香噴噴雞腿，你還猶豫什麼？準備胃液吧。\n");
		set("unit", "根");
		set("value", 30);
		set("food_remaining", 4);
		set("food_supply", 40);
		set("wield_msg", "$N抓起一根$n，握在手中當武器。\n");
		set("material", "bone");
	}
	init_hammer(1);
	setup();
}

int finish_eat()
{
	if( !query("weapon_prop") ) return 0;
	set_name("啃得精光的雞腿骨頭", ({ "bone" }) );
	set_weight(150);
	set("long", "一根啃得精光的雞腿骨頭。\n");
	return 1;
}
