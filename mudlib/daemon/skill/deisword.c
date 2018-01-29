inherit SKILL;

mapping *action = ({
        ([      "action":               
"$N使一招「佇倚危樓風細細」，手中$w如一風一般卷向$n的$l",
                "dodge":                -20,
                "damage":               30,
                "damage_type":  "刺傷"
        ]),
        ([      "action":               
"$N使出蝶戀花劍中的「草色煙光殘照裏」，劍光向殘照般灑向$n的$l",
                "dodge":                -20,
                "damage":               30,
                "damage_type":  "割傷"
        ]),
        ([      "action":               
"$N一招「無言誰會憑欄意」，手中$w默默的削向$n的$l",
                "dodge":                -30,
                "damage":               20,
                "damage_type":  "割傷"
        ]),
        ([      "action":               
"$N手中$w一式「擬把疏狂圖一醉」對準$n的$l一連刺出七劍",
                "damage":                90,
                "damage_type":  "刺傷"
        ]),
        ([      "action":               
"$N的$w憑空一指，一招「衣帶漸寬終不悔」刺向$n的$l",
                "dodge":                20,
                "damage":               40,
                "damage_type":  "刺傷"
        ]),
        ([      "action":               
"$N手中$w向外一分，使一招「爲伊消得人憔悴」反手對準$n$l一劍刺去",
                "dodge":                -20,
                "damage":               20,
                "damage_type":  "刺傷"
        ]),
});

int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 50 )
                return notify_fail("你的內力不夠，沒有辦法練蝶戀花劍法。\n");

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "sword" )
                return notify_fail("你必須先找一把劍才能練劍法。\n");

        return 1;
}

int valid_enable(string usage)
{
        return usage=="sword" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 30
        ||      (int)me->query("force") < 3 )
                return 
notify_fail("你的內力或氣不夠，沒有辦法練習蝶戀花劍法。\n");
        me->receive_damage("kee", 30);
        me->add("force", -3);
        write("你按著所學練了一遍蝶戀花劍法。\n");
        return 1;
}

string perform_action_file(string action)
{
        return CLASS_D("legend") + "/deisword/" + action;
}
 
int effective_level() { return 13;}

string *parry_msg = ({
        "$n使出一招「望極春愁」，手中的$v盪開了$N的$w。\n",
        "$n使出「黯黯生天際」，將$N的$w封於丈外。\n",
        "$n使出一招「強樂還無味」，手中的$v化做漫天殘照，盪開了$N的$w。\n",
        "$n手中的$v一抖，一招「對酒當歌」，向$N拿$w的手腕削去。\n",
});

string *unarmed_parry_msg = ({
        "$n將手中的$v舞得密不透風，一招「擬對強衣爲」封住了$N的攻勢。\n",
        "$n反手一招「佇望黯草無」，整個人消失在一團劍光之中。\n",
        "$n使出一招「倚極黯色言」，$v直刺$N的雙手。\n",
        "$n將手中的$v一抖，一招招「把酒樂帶伊」，迫得$N連連後退。\n",
});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}

int learn_bonus()
{
        return 10;
}
int practice_bonus()
{
        return 5;
}
int black_white_ness()
{
        return 20;
}
