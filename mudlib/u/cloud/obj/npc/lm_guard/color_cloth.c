// color_cloth.c

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("舞蝶彩衫", ({ "color cloth", "cloth" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "這件淡綠色的綢衫上面繡著幾隻彩蝶，煞是好看。\n");
		set("unit", "件");
		set("value", 800);
		set("material", "cloth");
		set("armor_prop/armor", 1);
		set("armor_prop/personality", 2);
		set("female_only", 1);
	}
	setup();
}

