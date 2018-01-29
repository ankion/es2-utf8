
#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void create()
{
        set_name( HIW "追風劍" NOR, ({ "windsword", "sword" }) );
        set_weight(7000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "這是一把淡青色的的長劍，看上去鋒利異常。\n");
                set("value", 1000000);
                set("material", "crimsonsteel");
                set("wield_msg", "$N「唰」地一聲抽出一把$n握在手中。\n");
                set("unequip_msg", "$N將手中的$n插入劍鞘。\n");
		set("weapon_prop/attack",5);
		set("weapon_prop/courage",10);
        }
        init_sword(70);
        setup();
}

