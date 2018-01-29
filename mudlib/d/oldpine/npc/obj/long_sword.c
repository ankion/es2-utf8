// long_sword.c

#include <weapon.h>

inherit SWORD;

void create()
{
	set_name("長劍", ({ "long sword", "sword" }) );
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("value", 700);
		set("material", "iron");
		set("long",
			"一把粗製濫造的長劍，把手部份用布纏繞了好幾圈以防止武器脫手。\n");
	}
	init_sword(25);
	setup();
}
