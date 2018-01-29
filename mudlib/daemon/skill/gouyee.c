// gouyee.c

inherit FORCE;

int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me)
{
        if( (int)me->query("max_mana") < (int)me->query_skill("gouyee") * 5 )
                return 
notify_fail("你的魔力不夠，無法提升谷衣心法的造詣。\n");

        return 1;
}

int practice_skill(object me)
{
        return 
notify_fail("谷衣心法只能用學的，或是從運用(exert)中增加熟練度。\n");
}

string exert_function_file(string func)
{
        return CLASS_D("taoist") + "/gouyee/" + func;
}
 
