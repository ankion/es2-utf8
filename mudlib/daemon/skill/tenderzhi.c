// tenderzhi.c

inherit SKILL;

mapping *action = ({
        ([      "action":               
"$N左手一揮，一招「菊樓採月」右手點向$n$l",
                "dodge":                -30,
                "parry":                30,
                "force":                80,
                "damage_type":  "刺傷",
                "weapon":               "右手食指",
        ]),
        ([      "action":               
"$N使一招「雪橋翦梅」，身影忽前忽後，突然一轉身左手往$n的$l點去",
                "dodge":                -30,
                "parry":                30,
                "force":                90,
                "damage_type":  "刺傷",
                "weapon":               "左手中指",
        ]),
        ([      "action":               
"$N身法稍頓，左手一揚使出「柳亭簪花」往$n的$l點去",
                "dodge":                -30,
                "parry":                30,
                "force":                140,
                "damage_type":  "刺傷",
                "weapon":               "左手中指",
        ]),
        ([      "action":               
"只見$N纖腰一擺，陡然滑出數尺，右手順著來勢一招「桃墳撲蝶」往$n的$l點去",
                "dodge":                -30,
                "parry":                30,
                "force":                90,
                "damage_type":  "刺傷",
                "weapon":               "右手食指",
        ]),
});

int valid_learn(object me)
{
        if( (string)me->query("gender") != "女性" )
                return notify_fail("柔虹指是隻有女子才能練的武功。\n");
        if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
                return notify_fail("練柔虹指必須空手。\n");
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
        if( (int)me->query("sen") < 30 )
                return notify_fail("你的精神無法集中了，休息一下再練吧。\n");
        if( (int)me->query("force") < 10 )
                return notify_fail("你的內力不夠了。\n");

        me->receive_damage("sen", 30);
        me->add("force", -10);

        return 1;
}
 
