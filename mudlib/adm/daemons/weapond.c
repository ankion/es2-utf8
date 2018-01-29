// weapond.c

#include <ansi.h>
#include <combat.h>

mapping weapon_actions = ([
        "slash": ([
                "damage_type":  "割傷",
                "action":               "$N揮動$w，斬向$n的$l",
                "parry":                20,
                ]),
        "slice": ([
                "damage_type":  "砍傷",
                "action":               "$N用$w往$n的$l砍去",
                "dodge":                20,
                ]),
        "chop": ([
                "damage_type":  "劈傷",
                "action":               "$N的$w朝著$n的$l劈將過去",
                "parry":                -20,
                ]),
        "hack": ([
                "action":               "$N揮舞$w，對準$n的$l一陣亂砍",
                "damage_type":  "砍傷",
                "damage":               30,
                "dodge":                30,
                ]),
        "thrust": ([
                "damage_type":  "刺傷",
                "action":               "$N用$w往$n的$l刺去",
                "dodge":                15,
                "parry":                -15,
                ]),
        "pierce": ([
                "action":               "$N的$w往$n的$l狠狠地一捅",
                "damage_type":  "刺傷",
                "dodge":                -30,
                "parry":                -30,
                ]),
        "whip": ([
                "action":               "$N將$w一揚，往$n的$l抽去",
                "damage_type":  "鞭傷",
                "dodge":                -20,
                "parry":                30,
                ]),
        "impale": ([
                "action":               "$N用$w往$n的$l直戳過去",
                "damage_type":  "刺傷",
                "dodge":                -10,
                "parry":                -10,
                ]),
        "bash": ([
                "action":               "$N揮舞$w，往$n的$l用力一□",
                "damage_type":  "挫傷",
                "post_action":  (: call_other, __FILE__, "bash_weapon" :),
                ]),
        "crush": ([
                "action":               "$N高高舉起$w，往$n的$l當頭砸下",
                "damage_type":  "挫傷",
                "post_action":  (: call_other, __FILE__, "bash_weapon" :),
                ]),
        "slam": ([
                "action":               
"$N手握$w，眼露兇光，猛地對準$n的$l揮了過去",
                "damage_type":  "挫傷",
                "post_action":  (: call_other, __FILE__, "bash_weapon" :),
                ]),
        "throw": ([
                "action":               "$N將$w對準$n的$l射了過去",
                "damage_type":  "刺傷",
                "post_action":  (: call_other, __FILE__, "throw_weapon" :),
                ]),
]);

varargs mapping query_action()
{
        string verb, *verbs;

        verbs = previous_object()->query("verbs");

        if( !pointerp(verbs) ) return weapon_actions["hit"];
        else {
                verb = verbs[random(sizeof(verbs))];
                if( !undefinedp(weapon_actions[verb]) ) return 
weapon_actions[verb];
                else return weapon_actions["hit"];
        }       
}

void throw_weapon(object me, object victim, object weapon, int damage)
{
        if( objectp(weapon) ) {
                if( (int)weapon->query_amount()==1 ) {
                        weapon->unequip();
                        tell_object(me, "\n你的" + weapon->query("name") + 
"用完了！\n\n");
                }
                weapon->add_amount(-1);
        }
}

void bash_weapon(object me, object victim, object weapon, int damage)
{
        object ob;
        int wap, wdp;

        if( objectp(weapon)
        &&      damage==RESULT_PARRY
        &&      ob = victim->query_temp("weapon") ) {
                wap = (int)weapon->weight() / 500
                        + (int)weapon->query("rigidity")
                        + (int)me->query("str");
                wdp = (int)ob->weight() / 500
                        + (int)ob->query("rigidity")
                        + (int)victim->query("str");
                wap = random(wap);
                if( wap > 2 * wdp ) {
                        message_vision(HIW "$N只覺得手中" + ob->name() + 
"把持不定，脫手飛出！\n" NOR,
                                victim);
                        ob->unequip();
                        ob->move(environment(victim));
                        victim->reset_action();
                } else if( wap > wdp ) {
                        message_vision("$N只覺得手中" + ob->name() + 
"一震，險些脫手！\n",
                                victim);
                } else if( wap > wdp / 2 ) {
                        message_vision(HIW "只聽見「啪」地一聲，$N手中的" + 
ob->name()
                                + "已經斷爲兩截！\n" NOR, victim );
                        ob->unequip();
                        ob->move(environment(victim));
                        ob->set("name", "斷掉的" + ob->query("name"));
                        ob->set("value", (int)ob->query("value") / 10);
                        ob->set("weapon_prop", 0);
                        victim->reset_action();
                } else {
                        message_vision("$N的" + weapon->name() + "和$n的" + 
ob->name()
                                + "相擊，冒出點點的火星。\n", me, victim);
                }
        }
}
 
