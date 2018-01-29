// necromancy.c

inherit SKILL;

string type() { return "knowledge"; }

int valid_enable(string usage) { return usage=="spells"; }

int valid_learn(object me)
{
	if( (int)me->query_skill("taoism") < (int)me->query_skill("necromancy")/2 )
		return notify_fail("你的天師正道修爲不夠，無法領悟更高深的茅山道術。\n");
	return 1;
}

string cast_spell_file(string spell)
{
	return CLASS_D("taoist") + "/necromancy/" + spell;
}

string scribe_spell_file(string spell)
{
	return CLASS_D("taoist") + "/necromancy/" + spell;
}

int practice_skill(object me)
{	
	object bug;

	if( bug = me->query_temp("mind_bug") )
		return notify_fail("你的魂魄還沒有全部收回，趕快殺死你的"
			+ bug->name() + "吧！\n");

	if( (int)me->query("mana") < 10 )
		return notify_fail("你的法力不夠。\n");

	if( (int)me->query("sen") < 30 )
		return notify_fail("你的精神無法集中。\n");

	me->add("mana", -10);
	me->receive_damage("sen", 30);

	write("你閉目凝神，神遊物外，開始修習茅山道術中的法術....\n");
	if( random((int)me->query("sen")) < 5 ) {
		int rnd;

		rnd = random(me->query_skill("spells", 1));
		if( rnd < 10 )	bug = new("/obj/npc/mind_bug");
		else			bug = new("/obj/npc/mind_beast");

		write("可是你心思一亂，變出了一隻面目猙獰的" + bug->name() + "！\n");
		bug->move(environment(me));
		bug->kill_ob(me);
		me->fight(bug);
		me->set_temp("mind_bug", bug);
		bug->set("owner", me->query("id"));
		return notify_fail("你的魂魄正被" + bug->name() + "纏住，快把它除掉吧！\n");
	}	
	else return 1;
}
