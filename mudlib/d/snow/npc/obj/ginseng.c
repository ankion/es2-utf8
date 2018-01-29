// ginseng.c

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("人蔘", ({ "ginseng" }) );
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一根約食指長的人蔘，據說常吃這種補品可以延年益壽。\n");
		set("unit", "根");
		set("value", 3000);
		set("food_remaining", 1);
		set("eat_func", (: eat_tonic :) );
		set("tonic", ([ "atman": 5, "max_atman": 150 ]) );
		set("food_supply", 30);
	}
}
