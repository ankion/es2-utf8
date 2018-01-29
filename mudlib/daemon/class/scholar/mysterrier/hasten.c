// hasten.c

#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
        string msg;
        int count;

        if( !me->is_fighting() )
                return notify_fail("「玄羽亂舞」只能在戰鬥中使用。\n");

        if( (int)me->query("kee") < 70 ) return notify_fail("你的氣不夠！\n");
        if( (int)me->query("force") - (int)me->query("max_force") < 70 )
                return notify_fail("你的真氣不夠！\n");

        msg = HIY "$N使出步玄七訣第一式「玄羽亂舞」，身法陡然加快！\n" NOR;

        message_vision(msg, me);
        count = (int)me->query_skill("mysterrier") / 20 + 2;
        if( count > 7 ) count = 7;
        while( count-- ) {
                object ob;

                me->clean_up_enemy();
                ob = me->select_opponent();
                if( !ob || (environment(ob) != environment(me))) {
                        message_vision(CYN "$N的身形轉了幾轉，倏地停住了腳步。\n" NOR, me);
                        break;
                } else
                        message_vision(CYN "$N迅捷無倫地在$n身旁繞了一圈 ...\n" NOR, me, ob);

                if( !COMBAT_D->fight(me, ob) )
                        message_vision(CYN "但是$N找不到機會出手！\n" NOR, me);
                me->receive_damage("kee", 10);
                me->add("force", -10);
        }

        me->start_busy(3);
        return 1;
}
