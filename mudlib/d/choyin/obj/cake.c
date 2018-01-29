// cake.c

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("大餅", ({ "big cake", "cake" }) );
	set_weight(130);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一個香噴噴、熱騰騰的大包子。\n");
		set("unit", "個");
		set("value", 25);
		set("food_remaining", 5);
		set("food_supply", 60);
	}
}
