// taoism.c

inherit SKILL;

void create() { seteuid(getuid()); }

string type() { return "knowledge"; }

int valid_learn(object me) 
{
        if( (int)me->query("bellicosity") > 100 )
                return notify_fail("你的殺氣太重，無法修煉天師正道。\n");
        return 1;
}

int practice_skill(object me)
{       
        return notify_fail("法術類技能必須用學的或是從實戰中獲取經驗。\n");
}
