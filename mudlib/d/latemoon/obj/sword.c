// bamboo_sword.c

#include <weapon.h>

inherit SWORD;

void create()
{
    set_name("紫玉寶劍", ({ "yu sword", "sword" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("value", 100);
		set("material", "bamboo");
        set("long", "這是一把寶劍，隱含神祕力量。\n");
        set("wield_msg", "$N拿出一把別緻的$n，握在手中。\n");
		set("unequip_msg", "$N放下手中的$n。\n");
	}
    init_sword(27);
	setup();
}
