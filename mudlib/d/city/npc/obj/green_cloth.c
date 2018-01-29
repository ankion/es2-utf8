// pink_cloth.c

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("淡青長袍", ({ "green cloth", "cloth" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "這件淡青長袍綢衫上面繡著幾隻黃鵲，聞起來還有一股淡香。\n");
		set("unit", "件");
		set("value", 26000);
		set("material", "cloth");
		set("armor_prop/armor", 1);
		set("armor_prop/personality", 5);
	}
	setup();
}

