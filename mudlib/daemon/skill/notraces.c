inherit SKILL;

string *dodge_msg = ({
        "$n一招「夕陽殘雪」輕輕巧巧地避了開去。\n",
        "只見$n身影一晃，一式「騰雲駕霧」早已避在七尺之外。\n",
        "$n使出「魚翔藍天」，輕輕鬆鬆地閃過。\n",
        "$n左足一點，一招「步履雲端」騰空而起，避了開去。\n",
        "可是$n使一招「踏雪無痕」，身子輕輕飄了開去。\n",
        "$n身影微動，已經藉一招「龍騰萬里」輕輕閃過。\n"
});

int valid_enable(string usage)
{
        return (usage=="dodge") || (usage=="move");
}

int valid_learn(object me)
{
        if( (int)me->query("max_force") < 50 )
                return notify_fail("你的內力不夠，沒有辦法練踏雪無痕。\n");

        return 1;
}

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 30
        ||      (int)me->query("force") < 3 )
                return notify_fail("你的氣或內力不夠，不能練踏雪無痕。\n");
        me->receive_damage("kee", 30);
        me->add("force", -3);
        return 1;
}
int effective_level() { return 12;}

int learn_bonus()
{
        return 20;
}
int practice_bonus()
{
        return 10;
}
int black_white_ness()
{
        return 20;
}

