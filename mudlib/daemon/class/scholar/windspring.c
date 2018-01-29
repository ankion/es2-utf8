// windspring.c

#include <ansi.h>
#include <weapon.h>

inherit SWORD;
// inherit F_UNIQUE;

void create()
{
        set_name( CYN "風泉之劍" NOR, ({ "sword of windspring", "sword" }) );
        set_weight(14000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long",
                        "這是步玄派歷代相傳的掌門信物，湛藍色的劍身跟鵝黃色劍柄，使\n"
                        "得風泉之劍成爲具有「劍之王者」的美譽，除此之外，這把劍也是\n"
                        "削鐵如泥的利器。\n");
                set("value", 35000);
                set("material", "sapphire");
                set("wield_msg", "$N「刷」地一聲抽出一柄閃著寒光的$n握在手中。\n");
                set("unequip_msg", "$N將手中的$n插入腰間的劍鞘。\n");
                set("weapon_prop/courage", 15);
                set("weapon_prop/intelligence", 15);
                set("weapon_prop/personality", 15);
                set("rigidity", 40);
                set("replica_ob", "/obj/longsword");
        }

        init_sword(75);
        setup();
}

void owner_is_killed(object killer)
{
        object soul;

        if( environment()->id("sword soul") ) return;

        if( !killer ) killer = environment();
        seteuid(getuid());
        soul = new(__DIR__"sword_soul");
        soul->move(environment(killer));
//	this_object()->move(soul);
//	this_object()->wield();	
        soul->reset_action();

        tell_room(environment(killer),
                "\n你看到風泉之劍掉落在地上 ... \n"
                "\n不 ... 它飄了起來！一個人形忽然浮現，手中正握著風泉之劍！\n\n");
        soul->chant();
	destruct(this_object());
}
