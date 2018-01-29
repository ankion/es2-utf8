// animate.c

inherit F_CLEAN_UP;

int cast(object me, object target)
{
        if( me->is_fighting() ) return notify_fail("你正在戰鬥中！\n");
        
        if( !target || !target->is_corpse() ) return 
notify_fail("你要驅動哪一具屍體？\n");
        
        if( (int)me->query("mana") < 50 ) return 
notify_fail("你的法力不夠了！\n");

        message_vision(
                
"$N對著地上的$n喃喃地念了幾句咒語，$n抽搐了幾下竟站了起來！\n", me, target);

        target->animate(me, (int)me->query_skill("spells") * 3 + 30);

        me->add("mana", -50);
        me->receive_damage("sen", 30);

        return 1;
}
 
