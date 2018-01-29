// iron-cloth.c

inherit SKILL;

string *absorb_msg = ({
        "$n已有準備，不慌不忙的運起鐵布衫。\n",
        "$n閉目凝神，氣走全身，護體硬功達到巔峯狀態。\n",
        "$n「嘿」的一聲，不躲不閃，運起鐵布衫迎向$N！\n",
});

string query_absorb_msg()
{
        return absorb_msg[random(sizeof(absorb_msg))];
}

int learn_bonus()
{
        return 10;
}
int practice_bonus()
{
        return 0;
}
int black_white_ness()
{
        return 0;
}
