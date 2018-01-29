// glaive.c

#include <weapon.h>

inherit BLADE;

void create()
{
	set_name("鬼頭刀", ({ "glaive" }) );
	set_weight(20000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("value", 1500);
		set("material", "steel");
		set("long", "這是一把沈重的鬼頭刀，刀柄上雕著 一個醜陋可怖的鬼頭正裂開了嘴大笑。\n");
		set("wield_msg", "$N抽出一把背厚刃薄的$n握在手中。\n");
		set("unequip_msg", "$N將手中的$n插入腰間的刀鞘。\n");
	}
	init_blade(45);
	setup();
}
