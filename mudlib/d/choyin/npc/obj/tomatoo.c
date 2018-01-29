// cake.c

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("山藥蛋", ({ "tomatoo"}) );
	set_weight(130);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "圓溜溜的山藥蛋，忒新鮮。\n");
		set("unit", "個");
		set("value", 25);
		set("food_remaining", 5);
		set("food_supply", 10);
	}
}
