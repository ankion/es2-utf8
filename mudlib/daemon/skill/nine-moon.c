#include <ansi.h>

inherit SKILL;

mapping *action = ({
        ([      "name":                 "陰魂不散",
                "action":               "$N使一招「陰魂不散」，手中$w劍光暴長，
 向$n的$l刺去",
                 "dodge":                50,
                 "damage":               170,
                 "damage_type":  "刺傷"
         ]),
        ([      "name":                 "陰氣森森",
                "action":               "$N劍隨身轉，一招「陰氣森森」罩向$n的$l",
                 "dodge":                -70,
                 "damage":               20,
                 "damage_type":  "刺傷"
         ]),
        ([      "name":                 "陰雲迭起",
                "action":               "$N舞動$w，一招「陰雲迭起」挾著無數劍光
刺向$n的$l",                
                 "dodge":                -40,
                 "damage":               90,
                 "damage_type":  "刺傷"
         ]),
        ([      "name":                 "陰曹地府",
                "action":               "$N手中$w龍吟一聲，祭出「陰曹地府」往$n
的$l刺出數劍",                
                 "dodge":                -40,
                 "damage":               40,
                 "damage_type":  "刺傷"
         ]),
        ([      "name":                 "陰陽兩儀",
                "action":               "$N手中$w劍光暴長，一招「陰陽兩儀」往$n$l
刺去",
                 "dodge":                60,
                 "damage":               120,
                 "damage_type":  "刺傷"
         ]),
        ([      "name":                 "陰日陽月",
                "action":               "$N手中$w化成一道光弧，直指$n$l，一招「
陰日陽月」發出虎哮龍吟刺去",
                 "dodge":                -60,
                 "damage":               150,
                 "damage_type":  "刺傷"
         ]),
});

int valid_learn(object me)
{
        object ob;
        if( (string)me->query("gender") != "女性" )
                 return notify_fail("九陰赤煉劍法是隻有女子才能練的武功。\n");
        if( (int)me->query("max_force") < 50 )
                return notify_fail("你的內力不夠，沒有辦法練九陰赤煉劍法。\n");
        if( (string)me->query_skill_mapped("force")!= "nine-moon-force")
                 return notify_fail("九陰赤煉劍法必須配合九陰心經才能練。\n");
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
                return notify_fail("你的內力或氣不夠，沒有辦法練習九陰赤煉劍。\n
");
        me->receive_damage("kee", 30);
        me->add("force", -5);
        write("你按著所學練了一遍九陰赤煉劍法。\n");
        return 1;
}

int valid_effect(object me, object weapon, string name, int skill)
{
}

void skill_improved(object me)
{
        if( (int)me->query_skill("nine-moon-sword", 1)  % 10 == 0 ) {
                tell_object(me,
                        RED "\n你突然覺得一股陰氣衝上心頭，只覺得想殺人....\n\n"
  NOR);
                 me->add("bellicosity", 2000);
        } else
                me->add("bellicosity", 200);
}
string perform_action_file(string action)
{
        return CLASS_D("ninemoon") + "/ninemoonsword/" + action;
}

                                                                
                                                                                  