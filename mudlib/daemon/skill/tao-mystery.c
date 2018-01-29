// tao-mystery.c

inherit SKILL;

void create() { seteuid(getuid()); }

string type() { return "knowledge"; }

void skill_improved(object me)
{
	me->add("bellicosity", 100); 
}

int practice_skill(object me)
{       
        return notify_fail("法術類技能必須用學的或是從實戰中獲取經驗。\n");
}
