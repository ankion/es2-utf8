// mystsword.c

#include <ansi.h>

inherit SKILL;

mapping *action = ({
        ([      "name":                 "暮雪三嘆",
                "action":               "$N使一招「暮雪三嘆」，手中$w急如驟雨般地刺向$n$l",
                "dodge":                -30,
                "damage":               60,
                "damage_type":  "刺傷"
        ]),
        ([      "name":                 "處子弄笛",
                "action":               "$N身形一晃，一招「處子弄笛」向$n$l刺出一劍",
                "dodge":                -20,
                "damage":               80,
                "damage_type":  "刺傷"
        ]),
        ([      "name":                 "陽谷白練",
                "action":               "$N舞動$w，一招「陽谷白練」挾著閃閃劍光刺向$n的$l",
                "dodge":                -40,
                "damage_type":  "刺傷"
        ]),
        ([      "name":                 "薰容逐電",
                "action":               "$N手中$w一個圈轉，使出「薰容逐電」中鋒直進刺向$n的$l",
                "dodge":                -30,
                "damage":               100,
                "damage_type":  "刺傷"
        ]),
});

int valid_learn(object me)
{
        object ob;

        if( (int)me->query_skill("mystforce",1) < 30 )
                return notify_fail("你的步玄心法火候還不夠。\n");

        if( (int)me->query("max_force") < 100 )
                return notify_fail("你的內力不夠，沒有辦法練小步玄劍。\n");

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
        ||      (int)me->query("force") < 5 )
                return notify_fail("你的內力或氣不夠，沒有辦法練習小步玄劍。\n");
        me->receive_damage("kee", 30);
        me->add("force", -5);
        write("你按著所學練了一遍小步玄劍。\n");
        return 1;
}

