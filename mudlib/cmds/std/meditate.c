// meditate.c

#include <skill.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	int sen_cost, mana_gain;

	seteuid(getuid());
	
	if( me->is_fighting() ) return notify_fail("戰鬥中冥思——找死嗎？\n");

	if( !arg
	||	!sscanf(arg, "%d", sen_cost) )
		return notify_fail("你要花多少精神冥思？\n");

	if( sen_cost < 10 ) return notify_fail("你最少要花 10 點「神」才能冥思。\n");

	if( (int)me->query("sen") < sen_cost )
		return notify_fail("你現在精神太差了，進行冥思將會迷失，永遠醒不過來！\n");

	if( (int)me->query("kee") * 100 / (int)me->query("max_kee") < 70 )
		return notify_fail("你現在身體狀況太差了，無法集中精神！\n");

	if( (int)me->query("gin") * 100 / (int)me->query("max_gin") < 70 )
		return notify_fail("你現在身體狀況太虛弱了，無法進入冥思的狀態！\n");

	write("你盤膝而坐，靜坐冥思了一會兒。\n");

	me->receive_damage("sen", sen_cost);

	// This function ranged from 1 to 15 when sen_cost = 30
	mana_gain = sen_cost * ((int)me->query_skill("spells") 
		+ (int)me->query("spi") ) / 300;

	if( mana_gain < 1 ) {
		write("但是當你睜開眼睛，只覺得腦中一片空白。\n");
		return 1;
	}

	me->add("mana", mana_gain );

	if( (int)me->query("mana") > (int)me->query("max_mana") * 2) {
		if( (int)me->query("max_mana") >= (int)me->query_skill("spells", 1) * 10) {
			write("當你的法力增加的瞬間你忽然覺得腦中一片混亂，似乎魔力的提升已經到了瓶頸。\n");
		} else {
			write("你的魔力提高了！\n");
			me->add("max_mana", 1);
		}
		me->set("mana", me->query("max_mana"));
	}	
	
	return 1;
}
int help(object me)
{
        write(@HELP
指令格式 : meditate [<耗費「神」的量，預設值 30>]
 
靜坐冥思，將遊離的精神力有效地集中凝聚成能夠用來施展法術的能量
，藉以增加自己的法力。

請參考 help stat 
HELP
        );
        return 1;
}
