// sword:__DIR__"obj/sword.c" 長劍一把

#include <weapon.h>

inherit SWORD;

void create()
{
    set_name("長劍",({"sword"}));
	set_weight(5500);
	if( clonep() )
		set_default_object(__FILE__);
	else{
		set("unit", "把");
		set("long", "這是一把普通的鐵劍，看起來沒什麼奇特。\n");
	    	set("value", 420);
		set("material", "iron");
                set("wield_msg", "$N「唰」地一聲抽出一把$n握在手中。\n");
                set("unwield_msg", "$N將手中的$n插入腰間的劍鞘。\n");
        }
	init_sword(13);
	setup();
}

