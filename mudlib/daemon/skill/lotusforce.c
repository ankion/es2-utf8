// lotusforce.c

inherit FORCE;

int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me)
{
	if( (int)me->query_skill("buddhism") < (int)me->query_skill("lotusforce") )
		return notify_fail("你的大乘佛法修爲不夠，無法領會更高深的蓮華心法。\n");

	return 1;
}

int practice_skill(object me)
{
	return notify_fail("蓮華心法只能用學的，或是從運用(exert)中增加熟練度。\n");
}

string exert_function_file(string func)
{
	return CLASS_D("bonze") + "/lotusforce/" + func;
}
