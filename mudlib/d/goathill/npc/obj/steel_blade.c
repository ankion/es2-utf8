// steel_blade.c

#include <weapon.h>

inherit BLADE;

void create()
{
	set_name("鋼刀", ({ "steel blade", "blade" }) );
	set_weight(9000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("value", 700);
		set("material", "steel");
		set("long", "一把沈重的鋼刀，磨得又利又快，看起來相當具殺傷力。\n");
		set("wield_msg", "$N抽出一把明晃晃的$n握在手中。\n");
		set("unequip_msg", "$N將手中的$n插入腰間的刀鞘。\n");
		set("weapon_prop/karma", -4);
	}
	init_blade(30);
	setup();
}
