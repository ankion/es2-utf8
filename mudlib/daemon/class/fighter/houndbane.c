// houndbane.c

#include <ansi.h>
#include <weapon.h>

inherit BLADE;

void create()
{
	set_name( GRN "妖刀狗屠" NOR, ({ "houndbane blade", "houndbane", "blade" }) );
	set_weight(17000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "這是一把暗綠色的鬼頭刀，拿在手中沈甸甸地。\n");
		set("value", 42000);
		set("material", "crimsonsteel");
		set("wield_msg", "$N「颼」地一聲抽出一把背厚刃薄的$n握在手中。\n");
		set("unequip_msg", "$N將手中的$n插入腰間的刀鞘。\n");
		set("weapon_prop/courage",10);
	}

	init_blade(96);
	setup();
}
