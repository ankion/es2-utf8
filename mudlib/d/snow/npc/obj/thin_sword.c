// thin_sword.c

#include <weapon.h>

inherit SWORD;

void create()
{
	set_name("細劍", ({ "thin sword", "sword" }) );
	set_weight(1400);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("value", 700);
		set("material", "steel");
		set("long", "這是一把又細又長的劍，輕飄飄的像是女孩子家的玩意。\n");
		set("wield_msg", "$N抽出一把劍身細長的劍，握在手中。\n");
		set("unequip_msg", "$N放下手中的$n。\n");
		set("weapon_prop/courage", -4);
	}
	init_sword(16);
	setup();
}
