// essencemagic.c

inherit SKILL;

string type() { return "knowledge"; }

int valid_enable(string usage) { return usage=="magic"; }

int valid_learn(object me)
{
	if( (int)me->query_skill("buddhism") < 10
	||	(int)me->query_skill("buddhism") <= (int)me->query_skill("essencemagic") )
		return notify_fail("你的佛法修爲還不夠高深，無法學習八識神通。\n");
	return 1;
}

string conjure_magic_file(string spell)
{
	return CLASS_D("bonze") + "/essencemagic/" + spell;
}
