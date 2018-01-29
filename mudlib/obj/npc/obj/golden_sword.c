// golden_sword.c

#include <weapon.h>

inherit SWORD;

void create()
{
	set_name("金鋒劍", ({ "golden sword","sword"  }) );
	set_weight(20000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "一把閃閃發著金光的長劍。\n");
		set("value", 3400);
		set("material", "gold");
	}
	init_sword(40);

// These properties are optional, if you don't set them, it will use the
// default values.

	set("wield_msg", "$N「唰」地一聲抽出一把$n握在手中。\n");
	set("unwield_msg", "$N將手中的$n插入腰間的劍鞘。\n");

// The setup() is required.

	setup();
}
