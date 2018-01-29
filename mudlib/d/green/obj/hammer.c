#include <weapon.h>

inherit HAMMER;

void create()
{
	set_name("鐵錘", ({ "hammer" }) );
	set_weight(8000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("material", "iron");
	}

	init_hammer(10);
	setup();
}
