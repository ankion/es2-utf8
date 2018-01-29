inherit SKILL;

string *dodge_msg = ({
        "$n一招「秋風起兮白雲飛」輕輕巧巧地避了開去。\n",
        "只見$n身影一晃，一式「草木黃落兮雁南歸」早已避在七尺之外。\n",
        "$n使出「蘭有秀兮菊有芳」，輕輕鬆鬆地閃過。\n",
        "$n左足一點，一招「懷佳人兮不能忘」騰空而起，避了開去。\n",
        "可是$n使一招「泛樓船兮濟汾河」，身子輕輕飄了開去。\n",
        "$n身影微動，已經藉一招「橫中流兮揚素波」輕輕閃過。\n",
        "但是$n一招「簫鼓鳴兮發棹歌」使出，早已繞到$N身後！\n",
        "但是$n身形飄忽，輕輕一縱，一招「歡樂極兮哀情多」，避開這一擊。\n",
        "$n身形往上一拔，一招「少壯幾時兮奈老何」，一個轉折落在數尺之外。\n",

});

int valid_enable(string usage)
{
        return (usage=="dodge") || (usage=="move");
}

int valid_learn(object me)
{
        if( (int)me->query("max_force") < 50 )
                return notify_fail("你的內力不夠，沒有辦法練秋風步。\n");

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
                return notify_fail("你的氣或內力不夠，不能練秋風步法。\n");
        me->receive_damage("kee", 30);
        me->add("force", -3);
        return 1;
}
int effective_level() { return 15;}

int learn_bonus()
{
        return -20;
}
int practice_bonus()
{
        return -10;
}
int black_white_ness()
{
        return 40;
}
