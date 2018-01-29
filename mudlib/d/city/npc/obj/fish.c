inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("西湖醋魚", ({ "fish" }));
	set_weight(1000);

	if( clonep() )
		set_default_object(__FILE__);
	    else {
		set("long", "一盤西湖醋魚，香氣四溢，讓人垂涎欲滴。\n");
		set("unit", "盤");
		set("value", 500);
		set("food_remaining", 6);
		set("food_supply", 90);
		}
}

