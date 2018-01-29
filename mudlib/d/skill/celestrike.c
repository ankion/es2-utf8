// celestrike.c

inherit SKILL;

mapping *action = ({
	([	"action":		"$N使出一招「大天羅式」，右掌穿出擊向$n的$l",
		"dodge":		-30,
		"parry":		10,
		"force":		300,
		"damage_type":	"瘀傷"
	]),
	([	"action":		"$N使出一招「大天羅式」，左掌化虛爲實擊向$n的$l",
		"dodge":		-10,
		"parry":		-30,
		"force":		270,
		"damage_type":	"瘀傷"
	]),
	([	"action":		"$N使出天邪掌法「小天羅式」，如鬼魅般欺至$n身前，一掌拍向$n的$l",
		"dodge":		-30,
		"parry":		10,
		"force":		250,
		"damage_type":	"瘀傷"
	]),
	([	"action":		"$N雙掌一錯，使出「雪陽三連月」，對準$n的$l連續拍出三掌",
		"dodge":		10,
		"parry":		-30,
		"force":		360,
		"damage_type":	"瘀傷"
	]),
	([	"action":		"$N左掌畫了個圈圈，右掌推出，一招「靈動五方鼓」擊向$n$l",
		"dodge":		-20,
		"parry":		-30,
		"force":		340,
		"damage_type":	"瘀傷"
	]),
	([	"action":		"$N使出「風雷七星斷」，身形散作七處同時向$n的$l出掌攻擊",
		"dodge":		-70,
		"parry":		-10,
		"force":		380,
		"damage_type":	"瘀傷"
	]),
	([	"action":		"$N吐氣揚聲，一招「氣撼九重天」雙掌併力推出",
		"parry":		-40,
		"force":		420,
		"damage_type":	"瘀傷"
	]),
});

int valid_learn(object me)
{
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("練天邪神掌必須空手。\n");
	if( (int)me->query_skill("celestial", 1) < 20 )
		return notify_fail("你的天邪神功\火候不足，無法練天邪掌法。\n");
	if( (int)me->query("max_force") < 100 )
		return notify_fail("你的內力太弱，無法練天邪掌法。\n");
	return 1;
}

int valid_skill_usage(string usage)
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
	if( (int)me->query("force") < 5 )
		return notify_fail("你的內力不夠了，休息一下再練吧。\n");
	me->receive_damage("kee", 30);
	me->add("force", -5);
	return 1;
}
