// hat.c

#include <armor.h>

inherit HEAD;

void create()
{
	set_name("玉帶冠", ({ "hat" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "這是一頂鑲著美玉的帽冠。\n");
		set("unit", "頂");
		set("value", 400);
		set("material", "cloth");
		set("armor_prop/armor", 2);
		set("armor_prop/personality", 3);
	}
	setup();
}

