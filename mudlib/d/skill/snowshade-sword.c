// fonxansword.c

inherit SKILL;

mapping *action = ({
	([	"action":		"$N使一招「回光幻電」，手中$w幻一條疾光刺向$n的$l",
		"dodge":		-20,
		"damae":		30,
		"damage_type":	"刺傷"
	]),
	([	"action":		"$N使出天山雪影劍中的「風霜碎影」，$w連揮劍光霍霍斬向$n的$l",
		"dodge":		-20,
		"damae":		30,
		"damage_type":	"割傷"
	]),
	([	"action":		"$N一招「殘陽照雪」，縱身飄開數尺，手中$w斬向$n的$l",
		"dodge":		-30,
		"damae":		20,
		"damage_type":	"割傷"
	]),
	([	"action":		"$N手中$w中宮直進，一式「冰谷初虹」對準$n的$l刺出一劍",
		"dodge":		-40,
		"damage_type":	"刺傷"
	]),
	([	"action":		"$N縱身一躍，手中$w一招「長空雷隱」對準$n的$l斜斜刺出一劍",
		"dodge":		-40,
		"damage_type":	"刺傷"
	]),
	([	"action":		"$N的$w憑空一指，一招「斷石狼煙」刺向$n的$l",
		"dodge":		20,
		"damage":		40,
		"damage_type":	"刺傷"
	]),
});

int valid_learn(object me)
{
	object ob;

	if( (int)me->query("max_force") < 50 )
		return notify_fail("你的內力不夠，沒有辦法練雪影劍法。\n");

	if( (string)me->query_skill_mapped("force")!= "snowshade-force")
		return notify_fail("雪影劍法必須配合天山魔教的獨門雪影心法才能練。\n");

	if( !(ob = me->query_temp("weapon"))
	||	(string)ob->query("skill_type") != "sword" )
		return notify_fail("你必須先找一把劍才能練劍法。\n");

	return 1;
}

int valid_skill_usage(string usage)
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
	||	(int)me->query("force") < 3 )
		return notify_fail("你的內力或氣不夠，沒有辦法練習雪影劍法。\n");
	me->receive_damage("kee", 30);
	me->add("force", -3);
	write("你按著所學練了一遍雪影劍法。\n");
	return 1;
}
