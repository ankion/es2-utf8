// blade.c

#include <weapon.h>

inherit BLADE;

void create()
{
	set_name("烏檀木刀", ({ "ebony blade", "blade" }) );
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "這是一把黑黝黝的烏檀木刀，聞起來有一股淡淡的香氣。\n");
		set("value", 600);
		set("material", "wood");
		set("wield_msg", "$N「颼」地一聲抽出一把$n握在手中。\n");
		set("unwield_msg", "$N將手中的$n插入腰間的刀鞘。\n");
	}
	init_blade(37);
	setup();
}
