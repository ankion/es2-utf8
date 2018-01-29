// snowwhip.c

#include <ansi.h>

inherit SKILL;

mapping *action = ({
	([	"name":			"寒風起兮",
		"action":		"$N使一招「寒風起兮」，手中$w抖得筆直向$n的$l連刺數鞭",
		"dodge":		-10,
		"damage":		30,
		"damage_type":	"刺傷"
	]),
	([	"name":			"漫天飛雪",
		"action":		"$N身形一轉，一招「漫天飛雪」$w幻出滿天鞭影，虛虛實實地襲向$n的$l",
		"dodge":		-50,
		"damage":		20,
		"damage_type":	"瘀傷"
	]),
	([	"name":			"雪花翩翩",
		"action":		"$N力貫$w，一招「雪花翩翩」點點鞭影飄浮不定地點向$n的$l",
		"dodge":		-40,
		"damage":		25,
		"damage_type":	"刺傷"
	]),
	([	"name":			"積雪三尺",
		"action":	        "$N手中$w一抖，一招「積雪三尺」以一個怪異的角度往$n下盤捲去",
		"dodge":		-40,
		"damage":		30,
		"damage_type":	"瘀傷"
	]),
        ([
		"name":			"狂風驟雪",
		"action":		"$N手中一緊，使招「狂風驟雪」，手裏$w一鞭接著一鞭不停地抽向$n的$l",
		"dodge":		-50,
		"damage":		100,
		"damage_type":   "鞭傷"
        ]),
	([	"name":			"風雪交加",
		"action":		"$N一招「風雪交加」手中$w舞出一片鞭影掃向$n全身",
		"dodge":		-60,
		"damage":		150,
		"damage_type":	"瘀傷"
	]),
});

int valid_learn(object me)
{
	object ob;

	if( (int)me->query("max_force") < 150 )
		return notify_fail("你的內力不夠，沒有辦法練寒雪鞭法, 多練些內力再來吧。\n");

	if( !(ob = me->query_temp("weapon"))
	||	(string)ob->query("skill_type") != "whip" )
		return notify_fail("你必須先找一條鞭子才能練鞭法。\n");

	return 1;
}

int valid_enable(string usage)
{
	return usage=="whip";
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if( (int)me->query("kee") < 30
	||	(int)me->query("force") < 5 )
		return notify_fail("你的內力或氣不夠，沒有辦法練習寒雪鞭法。\n");
	me->receive_damage("kee", 30);
	me->add("force", -5);
	write("你按著所學練了一遍寒雪鞭法。\n");
	return 1;
}

int valid_effect(object me, object weapon, string name, int skill)
{
}

