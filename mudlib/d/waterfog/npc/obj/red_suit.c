// red_suit.c

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("鮮紅錦衣", ({ "crimson suit", "suit" }) );
	set_weight(6500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("long", "一件鮮紅色的錦衣，上面繡著水煙閣的金色烏鴉徽號。\n");
		set("material", "cloth");
		set("value", 2000);
		set("armor_prop/armor", 5);
		set("armor_prop/attack", 5);
		set("armor_prop/defense", -5);
	}
	setup();
}
