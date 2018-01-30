// respirate.c

#include <skill.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	int gin_cost, atman_gain;
	//string magic_skill;

	seteuid(getuid());
	
	if( me->is_fighting() )
		return notify_fail("戰鬥也是一種修行，但不能和靈力的修行同時進行。\n");

	if( !arg
	||	!sscanf(arg, "%d", gin_cost) )
		return notify_fail("你要花多少精力修行？\n");

	if( gin_cost < 10 ) return notify_fail("你最少要花 10 點精力才能進行修行。\n");

	if( (int)me->query("gin") < gin_cost )
		return notify_fail("你現在精力不足，無法修行靈力！\n");

	if( (int)me->query("kee") * 100 / (int)me->query("max_kee") < 70 )
		return notify_fail("你現在身體狀況太差了，無法集中精神！\n");

	if( (int)me->query("sen") * 100 / (int)me->query("max_sen") < 70 )
		return notify_fail("你現在精神狀況太差了，無法控制自己的心靈！\n");

	write("你閉上眼睛開始打坐。\n");

	me->receive_damage("gin", gin_cost);

	// This function ranged from 1 to 15 when gin_cost = 30
	atman_gain = gin_cost * ((int)me->query_skill("magic") 
		+ (int)me->query("spi") ) / 300;

	if( atman_gain < 1 ) {
		write("但是你一不小心卻睡著了。\n");
		return 1;
	}

	me->add("atman", atman_gain );

	if( (int)me->query("atman") > (int)me->query("max_atman") * 2) {
		if( (int)me->query("max_atman") >= (int)me->query_skill("magic", 1) * 10 ) {
			write("你忽然覺得一陣天旋地轉，頭漲得像要裂開一樣，似乎靈力的修行已經遇到了瓶頸。\n");
		} else {
			write("你的道行提高了！\n");
			me->add("max_atman", 1);
		}
		me->set("atman", me->query("max_atman"));
	}	
	
	return 1;
}

int help(object me)
{
        write(@HELP
指令格式 : respirate [<耗費「精」的量，預設值 30>]
 
打坐修行，利用「煉精化氣，煉氣化神，煉神還虛」的方法將你的精力
轉變成靈力。

請參考 help stats
HELP
        );
        return 1;
}
