// red_guay.c

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("紅龜□", ({ "red guay", "guay" }) );
	set_weight(180);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一個大紅龜□，上面蓋\了個印子：保境安民。\n");
		set("unit", "個");
		set("value", 25);
		set("food_remaining", 6);
		set("food_supply", 45);
	}
}
