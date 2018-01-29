// magic-array.c

inherit SKILL;

string type() { return "knowledge"; }

int valid_enable(string usage) { return usage=="spells"; }

int valid_learn(object me)
{
        if( (int)me->query_skill("tao-mystery") <= (int)me->query_skill("magic-array"))
                return notify_fail("你的小天魔道修爲不夠，無法領悟更高深的奇門遁甲之術。\n");
        return 1;
}

string cast_spell_file(string spell)
{
        return CLASS_D("juechen") + "/magic-array/" + spell;
}

int practice_skill(object me)
{
        return notify_fail("法術類技能必須用學的或是從實戰中獲取經驗。\n");
}

