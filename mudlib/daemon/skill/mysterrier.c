// mysterrier.c

inherit SKILL;

string *dodge_msg = ({
        "$n身影一轉，輕易地避開了這一招。\n",
        "$n身法飄忽，左一點，右一頓，早已閃在一旁。\n",
        "但是$n身影一側，在間不容髮之際從容地避開了這一招。\n",
        "$n身形陡然拔高，使$N的攻勢盡數落空。\n",
        "$n右足一點，身影向左滑開數尺，避了開去。\n",
});

int valid_enable(string usage)
{
        return (usage=="dodge") || (usage=="move");
}

int valid_learn(object me)
{
        if( me->query_skill_mapped("force") != "mystforce" )
                return notify_fail("步玄七訣必須配合步玄心法使用。\n");
	if ( me->query_skill("music") < me->query_skill("mysterrier")/2 )
		return notify_fail("你的音律之學修爲不夠，無法領悟更高深的步玄七訣。");

        return 1;
}

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 20
        ||      (int)me->query("sen") < 20 )
                return notify_fail("你的氣或神不夠，不能練步玄七訣。\n");
        me->receive_damage("kee", 20);
        me->receive_damage("sen", 20);
        return 1;
}

string perform_action_file(string action)
{
        return CLASS_D("scholar") + "/mysterrier/" + action;
}
