// powerfade.c

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
        int skill;

        if( target != me ) return 
notify_fail("你只能用天邪神功壓制自己的殺氣。\n");

        if( (int)me->query("force") < 100 )     return 
notify_fail("你的內力不夠。\n");
        if( me->query_temp("powerup") ) return 
notify_fail("你已經在運功中了。\n");
        if( (int)me->query("bellicosity") <= 0 )
                return notify_fail("你現在毫無殺氣。\n");

        skill = me->query_skill("force");

        me->add("bellicosity", - 100 - skill/3 );
        me->add("force", -100);
        me->receive_damage("sen", 100);

        message_vision(
                HIC "$N微一凝神，運起天邪神功，放慢呼吸，開始收斂自己的殺氣 
....\n" NOR, me);

        if( me->is_fighting()
        &&      (random(skill) < (int)me->query("cps") * 3 ) )
                me->unconcious();

        return 1;
}

void remove_effect(object me, int amount)
{
        me->add_temp("apply/attack", - amount);
        me->add_temp("apply/dodge", - amount);
        me->add_temp("apply/damage", - amount);
        me->delete_temp("powerup");
        tell_object(me, "你的天邪神功運行完畢，將內力收回丹田。\n");
}
 
