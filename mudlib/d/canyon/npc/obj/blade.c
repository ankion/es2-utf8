// blade:__DIR__"obj/blade.c" 刀一把

#include <weapon.h>

inherit BLADE;

void create()
{
    set_name("軍刀",({"blade"}));
	set_weight(5500);
	if( clonep() )
		set_default_object(__FILE__);
	else{
		set("unit", "柄");
		set("long", "這是一把普通的軍刀，看起來沒什麼奇特。\n");
		set("value", 450);
		set("material", "iron");
                set("wield_msg", "$N抽出一把明晃晃的$n握在手中。\n");
                set("unwield_msg", "$N將手中的$n插入腰間的刀鞘。\n");
        }
	init_blade(14);
	setup();
}

