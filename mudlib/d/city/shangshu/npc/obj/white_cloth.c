// pink_cloth.c

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("月白色長裙", ({ "white cloth", "cloth" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "簡簡單單的一套月白色長裙，上面並沒有什麼裝飾，但總給人一種天外仙子的感覺。\n");
		set("unit", "件");
		set("value", 600);
		set("material", "cloth");
//		set("armor_prop/armor", 1);
		set("armor_prop/personality", 4);
		set("female_only", 1);
	}
	setup();
}

