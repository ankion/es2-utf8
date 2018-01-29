// liuh-ken.c

inherit SKILL;

mapping *action = ({
        ([      "action":               "$N使一招「輕解羅裳」，對準$n的$l輕飄飄的掃去",
                "dodge":                -20,
                "parry":                20,
                "damage_type":  "瘀傷"
        ]),
        ([      "action":               "$N揚起右手，一招「獨上蘭舟」便往$n的$l拍去",
                "dodge":                -10,
                "parry":                10,
                "damage_type":  "瘀傷"
        ]),
        ([      "action":               "$N左手虛晃，右手「月滿西樓」往$n的$l擊出",
                "dodge":                -20,
                "parry":                20,
                "damage_type":  "瘀傷"
        ]),
        ([      "action":               "$N左手微分，右手一長使出一招「雁字回時」，抓向$n的$l",
                "dodge":                -50,
                "parry":                -30,
                "force":                100,
                "damage_type":  "抓傷"
        ]),
        ([      "action":               "$N倏地一個轉身，雙手一挑「一種相思」直摜$n$l",
                "dodge":                -10,
                "parry":                -60,
                "force":                110,
                "damage_type":  "瘀傷"
        ]),
        ([      "action":               "$N左手虛晃，右掌飄飄，一招「兩處閒愁」擊向$n$l",
                "dodge":                -20,
                "parry":                -50,
                "force":                150,
                "damage_type":  "挫傷"
        ]),
        ([      "action":               "$N右手在$n$l劃過，隨後一招「才下眉頭」左爪又向同一方位抓到",
                "parry":                -50,
                "force":                60,
                "damage_type":  "抓傷"
        ]),
        ([      "action":               "$N左手虛晃，右手握成拳，一招「卻上心頭」擊向$n$l",
                "dodge":                -20,
                "parry":                -50,
                "force":                150,
                "damage_type":  "挫傷"
        ]),
});

int valid_learn(object me)
{
        if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
                return notify_fail("練一剪梅花手必須空手。\n");
        return 1;
}

int valid_enable(string usage)
{
        return usage=="unarmed";
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 30 )
                return notify_fail("你的體力不夠了，休息一下再練吧。\n");
        me->receive_damage("kee", 30);
        return 1;
}
int effective_level() { return 15;}

string *parry_msg = ({
        "$n一招「紅藕香殘玉簟秋」，右手輕拂$N的面門，逼得$N中途撤回手中的$w。\n",
        "$n右手虛幌，左手一招「雲中誰寄錦書來」，逼得$N後退三步。\n",
        "$n以守爲攻，一招「花自飄零水自流」，輕拂$N握$w的手腕。\n",
        "$n一招「此情無計可消除」，輕輕一託$N握$w的手，引偏了$N的$w。\n",
});

string *unarmed_parry_msg = ({
        "$n一招「薄霧濃雲愁永晝」，逼得$N中途撤招。\n",
        "$n腳走陰陽，一招「東籬把酒黃昏後」，攻$N之必救。\n",
        "$n左手拂下，右手一招「花自飄零水自流」，將$N封於尺外。\n",
        "$n雙手齊出，使出一招「此情無計可消除」，$N的功勢入泥牛入海，消失得無影無蹤。\n",

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
        return -20;
}
int practice_bonus()
{
        return -20;
}
int black_white_ness()
{
        return 30;
}
