// exercise.c

#include <skill.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        int kee_cost, force_gain;

        seteuid(getuid());
        
        if( me->is_fighting() )
                return notify_fail("戰鬥中不能練內功，會走火入魔。\n");

        if( !stringp(me->query_skill_mapped("force")) )
                return notify_fail("你必須先用 enable 
選擇你要用的內功心法。\n");

        if( !arg
        ||      !sscanf(arg, "%d", kee_cost) )
                return notify_fail("你要花多少氣練功？\n");

        if( kee_cost < 10 ) return notify_fail("你最少要花 10 
點「氣」才能練功。\n");

        if( (int)me->query("kee") < kee_cost )
                return 
notify_fail("你現在的氣太少了，無法產生內息運行全身經脈。\n");

        if( (int)me->query("sen") * 100 / (int)me->query("max_sen") < 70 )
                return notify_fail("你現在精神狀況太差了，無法凝神專一！\n");

        if( (int)me->query("gin") * 100 / (int)me->query("max_gin") < 70 )
                return notify_fail("你現在精力不夠，無法控制內息的流動！\n");

        write("你坐下來運氣用功，一股內息開始在體內流動。\n");

        me->receive_damage("kee", kee_cost);

        // This function ranged from 1 to 15 when kee_cost = 30
        force_gain = kee_cost * ((int)me->query_skill("force", 1)
                + (int)me->query("con") ) / 300;

        if( force_gain < 1 ) {
                write("但是當你行功完畢，只覺得全身□麻。\n");
                return 1;
        }

        me->add("force", force_gain );

        if( (int)me->query("force") > (int)me->query("max_force") * 2) {
                if( (int)me->query("max_force") >= 
                        ((int)me->query_skill("force", 1) + 
me->query_skill("force")/5) * 10 ) {
                        
write("當你的內息遍佈全身經脈時卻沒有功力提升的跡象，似乎內力修爲已經遇到了瓶�
薄n");
                } else {
                        write("你的內力增強了！\n");
                        me->add("max_force", 1);
                }
                me->set("force", me->query("max_force"));
        }       
        
        return 1;
}

int help(object me)
{
        write(@HELP
指令格式 : exercise [<耗費「氣」的量，預設值 30>]

運氣練功，控制體內的氣在各經脈間流動，藉以訓練人體肌肉骨骼的耐
力、爆發力，並且用內力的形式將能量儲備下來。

請參考 help stats
HELP
        );
        return 1;
}
 
