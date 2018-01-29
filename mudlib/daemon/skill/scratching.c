
#include <ansi.h>

inherit SKILL;

mapping *action = ({
        ([      "name":                 "三清歸真",
                "action":               "$N一招「三清歸真」，手中$w挽起幾個劍花，刺向$n的$l",
                "dodge":                -40,
                "damage":               40,
                "damage_type":  "刺傷"
        ]),
        ([      "name":                 "衆士護佑",
                "action":               "$N身形一變，一招「衆士護佑」，$w罩向$n的$l",
                "dodge":                -50,
                "damage":               30,
                "damage_type":  "刺傷"
        ]),
        ([      "name":                 "天人合一",
                "action":               "$N揮動$w，一招「天人合一」挾著閃閃劍光襲向$n的$l",
                "dodge":                -40,
		"damage":		50,
                "damage_type":  "刺傷"
        ]),
        ([      "name":                 "羣魔辟易",
                "action":               "$N手中$w一掄，使出「羣魔辟易」往$n的$l惡狠狠的砍去",
                "dodge":                -40,
                "damage":               40,
                "damage_type":  "刺傷"
        ]),
        ([      "name":                 "西出紫關",
                "action":               "$N一招「西出紫關」，$w一帶，輕輕划向$n$l",
                "dodge":                -60,
                "damage":               20,
                "damage_type":  "刺傷"
        ]),
        ([      "name":                 "乾坤一擲",
                "action":               "$N身劍合一，幻化成一道光華，一招「乾坤一擲」撲向$n",
                "dodge":                50,
                "damage":               150,
                "damage_type":  "刺傷"
        ]),
});

int valid_learn(object me)
{
        if( (int)me->query("max_force") < 80 )
                return notify_fail("你的內力不夠，沒有辦法練天師劍法。\n");

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
        object ob;

	if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "sword" )
                return notify_fail("你必須先找一把劍才能練劍法。\n");

        if( (int)me->query("kee") < 30
        ||      (int)me->query("force") < 5 )
                return notify_fail("你的內力或氣不夠，沒有辦法練習天師劍法。\
");
        me->receive_damage("kee", 30);
        me->add("force", -5);
        write("你按著所學練了一遍天師劍法。\n");
        return 1;
}

int valid_effect(object me, object weapon, string name, int skill)
{
}


