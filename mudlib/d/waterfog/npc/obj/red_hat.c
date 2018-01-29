// red_hat.c

#include <armor.h>

inherit HEAD;

void create()
{
	set_name("鮮紅金烏冠", ({ "crimson hat", "hat" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "頂");
		set("long", "這是水煙閣武士常戴的紅色圓頂帽，帽緣鑲著一圈金線。\n");
		set("value", 800);
		set("armor_prop/attack", 2);
		set("armor_prop/defense", -2);
		set("armor_prop/armor", 4);
	}
	setup();
}
