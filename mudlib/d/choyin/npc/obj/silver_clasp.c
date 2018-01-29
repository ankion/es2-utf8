// silver_clasp.c

#include <armor.h>
#include <weapon.h>

inherit HEAD;
inherit F_DAGGER;

void create()
{
	set_name( "銀簪" , ({ "clasp" }) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "支");
		set("value", 800);
		set("material", "silver");

		set("armor_prop/armor", 1);
		set("armor_prop/personality", 2);
		set("female_only", 1);
		set("wear_msg", "$N細心地將一支$n插在髮髻上。\n");

		set("wield_msg", "$N將$n握在手中，竟當成一把匕首來使。\n");
	}
	init_dagger(6);
	setup();
}
