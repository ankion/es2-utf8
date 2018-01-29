inherit FORCE;

int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me) { return 1; }

int practice_skill(object me)
{
        return 
notify_fail("婆蘿蜜多心經只能用學的，或是從運用(exert)中增加熟練度。\n");
}

string exert_function_file(string func)
{
        return CLASS_D("lama") + "/polomiduo/" + func;
}
 
int effective_level() { return 15;}

int learn_bonus()
{
        return 20;
}
int practice_bonus()
{
        return 10;
}
int black_white_ness()
{
        return 90;
}
