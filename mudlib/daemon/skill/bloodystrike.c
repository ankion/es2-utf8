inherit SKILL;

mapping *action = ({
        ([      "action":               
"$N使出一招「苦海端無涯」，左掌虛幌，右掌穿出擊向$n的$l",
                "dodge":                -30,
                "parry":                10,
                "force":                50,
                "damage_type":  "瘀傷"
        ]),
        ([      "action":               
"$N使出一招「地獄似有門」，左掌化虛爲實擊向$n的$l",
                "dodge":                -10,
                "parry":                -30,
                "force":                 70,
                "damage_type":  "瘀傷"
        ]),
        ([      "action":               
"$N使出密宗大手印中的「天堂卻無路」，一掌拍向$n的$l",
                "dodge":                -30,
                "parry":                10,
                "force":                50,
                "damage_type":  "瘀傷"
        ]),
        ([      "action":               
"$N雙掌一錯，使出「密宗爲獨尊」，對準$n的$l連續拍出",
                "dodge":                10,
                "parry":                -30,
                "force":                160,
                "damage_type":  "瘀傷"
        ]),
        ([      "action":               
"$N左掌立於胸前，右掌推出，一招「萬念皆是空」擊向$n$l",
                "dodge":                -20,
                "parry":                -30,
                "force":                140,
                "damage_type":  "瘀傷"
        ]),
        ([      "action":               
"$N使出「佛雲以殺止殺」，身形凌空飛起，從空中當頭向$n的$l出掌攻擊",
                "dodge":                -70,
                "parry":                -10,
                "force":                280,
                "damage_type":  "瘀傷"
        ]),
});

int valid_learn(object me)
{
        if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
                return notify_fail("練密宗大手印必須空手。\n");
        return 1;
}

int valid_enable(string usage) { return usage=="unarmed"; }

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 30 )
                return notify_fail("你的體力不夠了，休息一下再練吧。\n");
        if( (int)me->query("force") < 5 )
                return notify_fail("你的內力不夠了，休息一下再練吧。\n");
        me->receive_damage("kee", 30);
        me->add("force", -5);
        return 1;
}
int effective_level() { return 8;}
 
string *parry_msg = ({
        "$n雙掌微合，使出一招「千里迎剎佛」，「啪」的一聲將$N的$w夾在雙掌之間。\n",
        "$n略一轉身，一招「撒手離紅塵」拍向$N拿着$w的手。\n",
        "$n使出「粘」字訣，雙掌一劃，引偏了$N的$w。\n",
});

string *unarmed_parry_msg = ({
        "$n步走陰陽，一招「我佛慈悲懷」虛空拍出三掌，逼得$N撤招自保。\n",
        "$n施展出「萬象皆歸空」，輕描淡寫的化解了$N的攻勢。\n",
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
        return 50;
}
int practice_bonus()
{
        return 25;
}
int black_white_ness()
{
        return 100;
}

