// wu-shun.c
// 小無相功
inherit FORCE;

int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me)
{
	if( (int)me->query_skill("literate") < (int)me->query_skill("wu-shun") )
		return notify_fail("你的文學素養不夠無法提升小無相功的造詣。\n");

	return 1;
}

int practice_skill(object me)
{
	return notify_fail("小無相功只能用學的或是從運用(exert)中增加熟練度。\n");
}

//string exert_function_file(string func)
//{
//	return CLASS_D("xiaoyao") + "/wu-shun/" + func;
//}

