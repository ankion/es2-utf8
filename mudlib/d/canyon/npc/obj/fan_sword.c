// sword:__DIR__"obj/fan_sword.c" 鐵扇劍一把

#include <weapon.h>

inherit SWORD;

void create()
{
    set_name("鐵扇劍",({ "fan sword","fan","sword" }));
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else{
		set("unit", "柄");
		set("long", "這是一柄羽狀的鐵劍，看起來蠻尖銳的。\n");
		set("value", 600);
		set("material", "iron");
                set("wield_msg", "$N「唰」地一聲從袖口抽出一把$n握在手中。\n");
                set("unwield_msg", "$N將手中的$n收入袖內。\n");
        }
	init_sword(20);
	setup();
}

