// concentrate.c

#include <ansi.h>

int exert(object me, object target)
{
        int mana_gain;

        if( target && target!=me )
                return notify_fail("「靈神訣」只能用來恢復自己的法力。\n");

        if( (int)me->query("force") < 30 )
                return notify_fail("你的內力不夠。\n");

        
        mana_gain =  10 + (int)me->query_skill("force")/5;
        if( mana_gain + (int)me->query("mana") > (int)me->query("max_mana") )
                me->set("mana", (int)me->query("max_mana"));
        else
                me->add("mana", mana_gain);
        me->add("force", -30);
        me->receive_damage("sen", 10);

        message_vision(
                HIY "$N閉目凝神，用谷衣心法的內力運轉了一次「靈神訣」...\n"
                "一股青氣從$N身上散出，匯聚在$P的頂心，然後緩緩淡去。\n" NOR, 
me);

        if( me->is_fighting() ) me->start_busy(1);

        return 1;
}
 
