// fight.c

#include <ansi.h>
#include <skill.h>
#include <dbase.h>
#include <origin.h>

#define MEWIN	1
#define OBWIN	2

inherit F_CLEAN_UP;
void start_biwu(object me, object ob);

int main(object me, string arg)
{
	object obj, old_target;

	if( !wizardp(me) && environment(me)->query("no_fight") )
		return notify_fail("這裏禁止戰鬥。\n");

/*	if (!environment(me)->query("biwu_per"))
		return notify_fail("想比武得去校武場啊。\n");
*/
	if(!arg || !objectp(obj = present(arg, environment(me))))
		return notify_fail("你想攻擊誰？\n");

	if( !obj->is_character() )
		return notify_fail("看清楚一點，那並不是生物。\n");

/*	if( obj->is_fighting(me) )
		return notify_fail("加油！加油！加油！\n");
*/
	if( !living(obj) )
		return notify_fail(obj->name() + "已經無法戰鬥了。\n"); 

	if(obj==me)	return notify_fail("瘋了？自己怎麼和自己比武？\n");

	if (!userp(obj))
		return notify_fail ("不要和npc比武哦。\n");  

	if( (object)obj->query_temp("pending/biwu")!=me ) {
		message_vision("\n$N對著$n說道：" 
			+ RANK_D->query_self(me) 
			+ me->name() + "，領教"
			+ RANK_D->query_respect(obj) + "的高招！\n\n", me, obj);
		if( objectp(old_target = me->query_temp("pending/biwu")) )
			tell_object(old_target, YEL + me->name() + "取消了和你比試的念頭。\n" NOR);
		me->set_temp("pending/biwu", obj);
		tell_object(obj, YEL "如果你願意和對方進行比試，請你也對" + me->name() + "("+(string)me->query("id")+")"+ "下一次 biwu 指令。\n" NOR);
		write(YEL "由於對方是由玩家控制的人物，你必須等對方同意才能進行比試。\n" NOR);
		return 1;
	}

	if( obj->query("can_speak") ) {
		message_vision("\n$N對著$n說道：" 
			+ RANK_D->query_self(me) 
			+ me->name() + "，領教"
			+ RANK_D->query_respect(obj) + "的高招！\n\n", me, obj);

		notify_fail("看起來" + obj->name() + "並不想跟你較量。\n");
		if( !userp(obj) && !obj->accept_biwu(me) ) return 0;

		start_biwu(me , obj);
}
	return 1;
}


void start_biwu(object me, object ob)
{
        int mycor, obcor, mykee, obkee, myeff_kee, obeff_kee;
        int turn, flag, i, j, k, l, flag1 = 0;
        float count, count_total = 0.0;

        if (!ob || ob == me)    return;

        // check cor, decide attack turns
        mycor = me->query_cor();
        obcor = ob->query_cor();
        if (mycor > obcor) {
                turn = mycor / obcor;
                count = (float) mycor / (float) obcor - turn;
                flag = 0;
                }
            else {
                turn = obcor / mycor;
                count = (float) obcor / (float) mycor - turn;
                flag = 1;
                }

        // attack until one failed
        for (;;) {
        // 1. fight
                if (!flag) {
                        for (i=0; i<= (turn+1)/2; i++)
                        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"));
                        COMBAT_D->do_attack(ob, me, ob->query_temp("weapon"));
                        count_total = count_total + count/2;
                        if (count_total > 1.) {
                          COMBAT_D->do_attack(me, ob, me->query_temp("weapon"));
                                count_total = count_total - 1.;
                                }
                        }
                    else {
                        for (i=0; i<= (turn+1)/2; i++)
                        COMBAT_D->do_attack(ob, me, ob->query_temp("weapon"));
                        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"));
                        count_total = count_total + count/2;
                        if (count_total > 1.) {
                          COMBAT_D->do_attack(ob, me, ob->query_temp("weapon"));
                                count_total = count_total - 1.;
                                }
                        }

        // 2.check if can continue
                mykee = me->query("kee");
		myeff_kee = me->query("eff_kee");
                obkee = ob->query("kee");
		obeff_kee = ob->query("eff_kee");
                if (mykee <= 0) {
                        me->set("kee", 1);
			flag1 = MEWIN;
			}
		if (myeff_kee <= 0) {
			me->set("eff_kee", 1);
			flag1 = MEWIN;
			}
                if (obkee <= 0) {
                        ob->set("kee", 1);
			flag1 = OBWIN;
			}
		if (obeff_kee <= 0) {
			ob->set("eff_kee", 1);
			flag1 = OBWIN;
			}
		if (flag1 == MEWIN) {
			message_vision("$N拱了拱手，說：“閣下武功不凡，佩服佩服！“\n", me);
			return;
			}
		    else if (flag1 == OBWIN) {
                        message_vision("$N拱了拱手，說：“閣下武功不凡，佩服佩服！“\n", ob);
                        return;
                        }
		
	// delay
/*		for (j=0; j<50;j ++)
			for (k=0; k<50; k++)
				for (l=0; l<50; l++);
 */       }
}























