// cucurbit.c

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("糖葫蘆", ({ "sugar cucurbit", "cucurbit", "sugar" }) );
	set_weight(180);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一串看起來就讓人垂涎欲滴的糖漬葫蘆。\n");
		set("unit", "串");
		set("value", 40);
		set("food_remaining", 4);
		set("food_supply", 50);
	}
}
