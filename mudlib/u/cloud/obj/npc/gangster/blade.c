// blade.c

#include <weapon.h>

inherit BLADE;

void create()
{
	set_name("鬼頭刀", ({ "blade" }) );
	set_weight(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("value", 700);
		set("material", "iron");
		set("long", "這種厚重的大刀，強盜喜歡用，份量大約十斤重。\n");
		set("wield_msg", "$N抽出一把表面斑駁的$n握在手中。\n");
		set("unequip_msg", "$N將手中的$n插回腰間。\n");
	}
	init_blade(25);
	setup();
}
