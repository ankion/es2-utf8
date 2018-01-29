// mystforce.c

inherit FORCE;

int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me) { return 1; }

int practice_skill(object me)
{
        return notify_fail ("步玄心法只能學，或是從運用(exert)中增加熟練度。\n"); 
}

/*string exert_function_file(string func)
{
        return CLASS_D("scholar") + "/fonxanforce/" + func;
}
*/ 
