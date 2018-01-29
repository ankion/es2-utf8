
// selflearn.c

#include <skill.h>

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
        string skill;
        int level, gin_cost;

        if(!arg || sscanf(arg, "%s", skill)!=1 )
                return notify_fail("指令格式：selflearn <技能> \n");

	if ( skill != "dodge" && skill !="force" && skill != "sword" &&
	     skill != "blade" && skill !="staff" && skill != "parry" && skill != "unarmed" )
		return notify_fail("這項技能不能通過自學取得進步！\n");

        if( me->is_fighting() )
                return notify_fail("臨陣磨槍？來不及啦。\n");

	if ( (int)me->query_skill(skill,1) < 40  )  {
		printf("你得有「%s」的入門知識才行。",to_chinese(skill));
		return notify_fail("\n");
	}

        gin_cost = 300 / (int)me->query("int");

        if( (int)me->query("learned_points") >= (int)me->query("potential") )
                return notify_fail("你的潛能已經發揮到極限了，沒有辦法再成長了。\n");

        printf("你開始鑽研有關「%s」的問題。\n", to_chinese(skill));
	level = (int)me->query_skill(skill,1);

        if( (int)me->query("gin") > gin_cost ) {
                if( level * level * level / 10 > (int)me->query("combat_exp") ) {
			printf("也許是缺乏實戰經驗，結果是一無所獲。\n" );
                } else {
                        printf("你苦思冥想，似乎有些心得。\n");
                        me->add("learned_points", 1);
                        me->improve_skill(skill, random(me->query("int")+level));
                }
        } else {
                gin_cost = me->query("gin");
                write("你今天太累了，結果什麼也沒有學到。\n");
        }

        me->receive_damage("gin", gin_cost );

        return 1;
}

