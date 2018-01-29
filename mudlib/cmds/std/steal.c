// steal.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        string what, who;
        object ob, victim;
        int sp, dp;

        if( environment(me)->query("no_fight") )
                return notify_fail("這裏禁止行竊。\n");

        if( me->query_temp("stealing") )
                return notify_fail("你已經在找機會下手了！\n");

        if( !arg || sscanf(arg, "%s from %s", what, who)!=2 ) return
                notify_fail("指令格式：steal <物品> from <人物>\n");

        victim = present(who, environment(me));
        if( !victim || victim==me) return 
notify_fail("你想行竊的對象不在這裏。\n");
        if( !wizardp(me) && wizardp(victim) )
                return notify_fail("玩家不能偷巫師身上的東西。\n");

        if( !ob = present(what, victim) ) {
                object *inv;
                inv = all_inventory(victim);
                if( !sizeof(inv) )
                        return notify_fail( victim->name() + 
"身上看起來沒有什麼值錢的東西好偷。\n");
                ob = inv[random(sizeof(inv))];
        }
        sp = (int)me->query_skill("stealing") * 5 + (int)me->query("kar") * 2
                - (int)me->query("thief") * 20;
        if( sp < 1 ) sp = 1;
        if( me->is_fighting() ) {
                sp /= 2;
                me->start_busy(3);
        }
        dp = (int)victim->query("sen") * 2 + (int)ob->weight()/25;
        if( victim->is_fighting() ) dp *= 10;
        if( ob->query("equipped") ) dp *= 10;

        write("你不動聲色地慢慢靠近" + victim->name() + "，等待機會下手 
...\n\n");

        me->set_temp("stealing", 1);
        call_out( "compelete_steal", 3, me, victim, ob, sp, dp);

        return 1;
}

void compelete_steal(object me, object victim, object ob, int sp, int 
dp)
{
        me->delete_temp("stealing");

        if( environment(victim) != environment(me) ) {
                tell_object(me, "太可惜了，你下手的目標已經走了。\n");
                return;
        }

        if( !living(victim) || (random(sp+dp) > dp) ) {
                if( !ob->move(me) ) {
                        tell_object(me, "你摸到一" + ob->query("unit") + 
ob->name() 
                                + "，可是對你而言太重了，不得不放棄。\n");
                        return;
                }
                tell_object(me, HIW "得手了！\n\n" NOR);
                tell_object(me, "你成功地偷到一" + ob->query("unit") + 
ob->name() + "！\n");
                if( living(victim) )
                        me->improve_skill("stealing", 
random(me->query("int")));
                if( random(sp) < dp/2 )
                        message("vision", "你看到" + me->name() + 
"鬼鬼祟祟地從"
                                + victim->name() + "身上偷走了一" + 
ob->query("unit")
                                + ob->name() + "！\n", environment(me), ({ 
me, victim }) );
        } else {
                if( random(sp) > dp/2 ) {
                        tell_object(me, victim->name() + 
"不經意地一轉頭，你急忙將手縮了回去！\n"
                                "還好，沒有被發現。\n");
                        return;
                }
                tell_object(me, HIR "糟糕！你失手了！\n\n" NOR);
                message_vision("$N一回頭，正好發現$n的手正抓著$P身上的" + 
ob->name() + "！\n\n"
                        + "$N喝道：「幹什麼！」\n\n", victim, me);
                me->improve_skill("stealing", 1,0 );
                if( userp(victim) ) victim->fight_ob(me);
                else victim->kill_ob(me);
                me->fight_ob(victim);
                me->start_busy(5);
                me->add("thief", 1);
        }
}

int help(object me)
{
write(@HELP
指令格式 : steal <某物> from <某人>

這個指令讓你有機會偷到他人身上的東西。成功了, 當然你就能獲得
該樣物品。可是, 馬有失蹄, 人總有失風的時候, 當你失敗時當然就
得付出代價, 至於是什麼代價......靠你自己去發掘羅。
HELP
    );
    return 1;
}
 
