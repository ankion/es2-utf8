// color_cloth.c

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("豔紅綢衫", ({ "cloth cloth", "cloth" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",
			"一件大紅色的女子衣衫，看起來有點鮮豔得過火。\n");
		set("unit", "件");
		set("value", 500);
		set("material", "cloth");
		set("armor_prop/armor", 1);
		set("armor_prop/personality", 1);
		set("female_only", 1);
	}
	setup();
}

