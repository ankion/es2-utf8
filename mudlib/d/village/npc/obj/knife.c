// Mon  08-21-95

#include <weapon.h>

inherit BLADE;

void create()
{
    set_name("菜刀", ({ "kitchen knife", "knife" }) );
    set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        set("long","一把舊舊的菜刀, 刀口幾乎被磨平了, 不過還頗具有殺傷力.\n");
        set("unit", "把");
		set("material", "iron");
	}
    init_blade(7);
	setup();
}

