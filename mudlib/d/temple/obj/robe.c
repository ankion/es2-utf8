// robe.c

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("青佈道袍", ({"robe","cloth"}) );
	set_weight(900);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一件式樣簡單的青佈道袍\n");
		set("unit", "件");
		set("value", 100);
		set("armor_prop/spells", 1);
	}
	setup();
}
