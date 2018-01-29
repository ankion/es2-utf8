inherit FORCE;

int valid_enable(string usage) { return usage=="iron-cloth"; }

int valid_learn(object me) { return 1; }

int practice_skill(object me)
{
        return 
notify_fail("金剛不壞功只能用學的。\n");
}

 
int effective_level() { return 20;}

string *absorb_msg = ({
        "$n雙臂一震，金剛不壞功力決堤似的澎湃而出。\n",
        "$n施展出金剛不壞功中的「彈」字訣，一股彈力傳入$N的體內。\n",
        "$n使出一招「苦海無涯」，凝虛爲實，渾身硬如金剛。\n",
        "$n施展出金剛不壞功，對抗$N的一擊之力。\n",
});

string query_absorb_msg()
{
        return absorb_msg[random(sizeof(absorb_msg))];
}

int bounce_ratio()
{
        return 10;
}

int learn_bonus()
{
        return -10;
}
int practice_bonus()
{
        return -5;
}
int black_white_ness()
{
        return 20;
}
