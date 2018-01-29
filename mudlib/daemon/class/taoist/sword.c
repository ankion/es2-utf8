// sword.c

#include <ansi.h>

#include <weapon.h>

inherit SWORD;

void create()
{
        set_name( HIR "咒劍王□" NOR, ({ "sword" }) );
        set_weight(7000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long",
                        
"這是一把桃木雕成的古劍，聞起來有一股香味，劍身刻著許多你從未見過的咒\n"
                        "文，只有劍柄部份有兩個依稀可以辨認的篆字：「 王 □ 
」\n");
                set("value", 18000);
                set("material", "steel");
                set("wield_msg", "$N「唰」地一聲抽出一把$n握在手中。\n");
                set("unequip_msg", "$N將手中的$n插入腰間的劍鞘。\n");
        }

        init_sword(44);
        setup();

        set("weapon_prop/spirituality", 30);
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int damage;

        if( victim->is_ghost() ) {
                if( random(me->query("max_atman")) > 
(int)victim->query("atman")/2 ) {
                        damage = me->query_spi();
                        victim->receive_wound("gin", damage);
                        me->receive_heal("gin", damage);
                        me->receive_heal("kee", damage);
                        me->receive_heal("sen", damage);
                        return HIY 
"王□劍發出一股金色的罡氣，流遍$N的全身。\n" NOR;
                }
                return random(me->query_spi());
        }
}
 
