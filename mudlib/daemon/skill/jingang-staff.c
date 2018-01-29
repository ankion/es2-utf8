// cloudstaff.c

inherit SKILL;

mapping *action = ({
        ([      "action":               
"$N使一招「天光乍現」，手中$w掃向$n下盤！",
                "damage":               40,
                "dodge":                10,
                "parry":                -40,
                "damage_type":  "挫傷"
        ]),
        ([      "action":               
"$N揮起$w，一招「雨後初晴」攻向$n$l！",
                "damage":               40,
                "dodge":                20,
                "parry":                -60,
                "damage_type":  "挫傷"
        ]),
        ([      "action":               
"$N橫過手中$w，使出「浮雲寫意」擊向$n$l！",
                "damage":               40,
                "dodge":                10,
                "parry":                -40,
                "damage_type":  "挫傷"
        ]),
        ([      "action":               
"$N使出一招「游龍穿雲」，$w一挺撞向$n$l！",
                "damage":               40,
                "dodge":                10,
                "parry":                -40,
                "damage_type":  "挫傷"
        ]),
});

int valid_learn(object me)
{
        if( (int)me->query("str") + (int)me->query("max_force") / 10 < 50 )
                return 
notify_fail("你的膂力還不夠，也許該練一練內力來增強力量。\n");

        return 1;
}

int valid_enable(string usage)
{
        return (usage=="staff") || (usage=="parry");
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        object weapon;

        if( !objectp(weapon = me->query_temp("weapon"))
        ||      (string)weapon->query("skill_type") != "staff" )
                return 
notify_fail("你必須先找一根木杖或者是類似的武器，才能練杖法。\n");

        if( (int)me->query("kee") < 60 )
                return 
notify_fail("你的體力不夠練這門杖法，還是先休息休息吧。\n");
        me->receive_damage("kee", 60);
        return 1;
}
 
