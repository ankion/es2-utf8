// sttormdance.c

inherit SKILL;

string *dodge_msg = ({
	"但是$n身法輕靈，翩翩地飄了開去！\n"
});

int valid_skill_usage(string usage)
{
	return (usage=="dodge");
}

int valid_learn(object me)
{
	if( (string)me->query("gender") != "女性" )
		return notify_fail("七寶天嵐舞只有女性才能練。\n");
	if( (int)me->query("spi") < 20 )
		return notify_fail("你的靈性不夠，沒有辦法練七寶天嵐舞。\n");

	return 1;
}

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
	if( (int)me->query("sen") < 30 )
		return notify_fail("你的精神太差了，不能練七寶天嵐舞。\n");
	me->receive_damage("sen", 30);
	return 1;
}
