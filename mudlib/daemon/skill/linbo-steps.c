// linbo-step.c
//凌波微步

inherit SKILL;

string *dodge_msg = ({
	"$n一招「瞻忽在前」輕輕鬆鬆地避了開去。\n",
	"只見$n身形一轉一式「動若脫兔」早已閃開$N的攻擊。\n",
	"$n使出「微塵不驚」身形微動，$N又撲了個空。\n",
	"$n左足一退右足一分，一招「若有若無」已避了開去。\n",
	"可是$n使一招「姑射仙人」身子象輕紗一樣飄了開去。\n",
	"$n下身不動，上身輕側已經藉一招「靜若處子」輕輕閃過。\n",
	"但是$n一招「瞻忽在後」使出竟然繞到$N身後！\n"
});

int valid_enable(string usage)
{
	return (usage=="dodge") || (usage=="move");
}

int valid_learn(object me)
{
	if( (int)me->query_skill("literate", 1) < 60 )
		return notify_fail("你的文學素養不夠沒有辦法練凌波微步。\n");

	return 1;
}

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
	if( (int)me->query("gin") < 80
	||	(int)me->query("sen") < 80 )
		return notify_fail("你的精神不足不能練凌波微步。\n");
	me->receive_damage("gin", 10);
	me->receive_damage("sen", 10);
	me->add("force", 3);
	return 1;
}

