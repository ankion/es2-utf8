// tea_leaf.c

#include <weapon.h>

inherit THROWING;

void create()
{
	set_name("茶葉", ({ "tea_leaf", "tea" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",	"才採的新茶，發出一股淡淡的香氣。\n");
		set("unit", "把");
		set("base_unit", "片");
		set("base_weight", 1);
		set("base_value", 1);
	}
	set_amount(10);
	init_throwing(1);
	setup();
}
