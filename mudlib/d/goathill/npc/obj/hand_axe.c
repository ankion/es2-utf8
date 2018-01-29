// hand_axe.c

#include <weapon.h>

inherit AXE;

void create()
{
	set_name("短斧", ({ "hand axe", "axe" }) );
	set_weight(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("value", 500);
		set("material", "steel");
		set("long",
			"這種斧頭的刃長柄短，是專門用來做兵器的斧頭，近戰具有相當強的\n"
			"殺傷力。\n");
		set("wield_msg", "$N抽出一柄$n握在手中。\n");
		set("unequip_msg", "$N將手中的$n插入腰間的束帶間。\n");
		set("weapon_prop/attack", 3);
		set("weapon_prop/defense", -2);
	}
	init_axe(22, SECONDARY);
	setup();
}
