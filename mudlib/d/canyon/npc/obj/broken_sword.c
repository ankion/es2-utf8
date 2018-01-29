// sword:__DIR__"obj/broken_sword.c" 破殘奇劍一把

#include <weapon.h>
#include <ansi.h>

inherit SWORD;
//inherit F_UNIQUE;

void create()
{
    set_name( HIW"ψ破 殘 奇 劍ψ" NOR,({"broken sword","sword"}));
	set_weight(4500);
	if( clonep() )
		set_default_object(__FILE__);
	else{
		set("unit", "把");
       	set("long", "劍鋒處缺了一角，缺角處發出異樣白光的奇劍。\n");
		set("value", 4000);
		set("material", "異類金屬");
        set("wield_msg", "$N「唰」地一聲抽出一把$n握在手中。\n");
        set("unwield_msg", "$N將手中的$n插入腰間的劍鞘。\n");
        set("replica_ob", "/obj/weapon/longsword");
    }
	init_sword(65);
	setup();
}

