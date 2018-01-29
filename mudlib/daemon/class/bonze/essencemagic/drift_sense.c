// drift_sense.c

#include <ansi.h>

inherit SSERVER;

int conjure(object me, object target)
{
	if( me->is_fighting() )
		return notify_fail("戰鬥中無法使用遊識神通！\n");
	if( me->query("atman") < 75 )
		return notify_fail("你的靈力不夠！\n");
	if( target )
		return notify_fail("遊識神通只能對自己使用！\n");
	write("你要移動到哪一個人身邊？");
	input_to( (: call_other, __FILE__, "select_target", me :));
	return 1;
}

void select_target(object me, string name)
{
	object ob;

	if( !name || name=="" ) {
		write("中止施法。\n");
		return;
	}

	ob = find_player(name);
	if( !ob || !me->visible(ob) || wizardp(ob) )
		ob = find_living(name);
	if( !ob || !me->visible(ob) || wizardp(ob) ) {
		write("你無法感受到這個人的靈力 ....\n");
		write("你要移動到哪一個人身邊？");
		input_to( (: call_other, __FILE__, "select_target", me :));
		return;
	}
	if( me->is_fighting() ) {
		write("戰鬥中無法使用遊識神通！\n");
		return;
	} else if( me->query("atman") < 75 ) {
		write("你的靈力不夠！\n");
		return;
	}

	me->add("atman", -75);
	me->receive_damage("gin", 30);
	
	message_vision( HIY "$N低頭閉目，開始施展遊識神通 ....\n" NOR, me);
        if ( me->is_ghost() ) {
                write("你失敗了。\n");
                return;
        }
	if( random(ob->query("max_atman")) > (int)me->query("atman") / 2 ) {
		write("你感受到對方的靈力，但是不夠強烈。\n");
		return;
	}
	if( random(me->query_skill("magic")) < (int)ob->query("atman") / 50 ) {
		write("你因爲不夠熟練而失敗了。\n");
		return;
	}
	message( "vision", HIY "\n一道耀眼的光芒忽然罩住" + me->name() 
		+ "，幾秒鐘後，光芒和人一齊消失得無影無蹤！\n\n", environment(me), ({ me }) );
	me->move(environment(ob));
	message( "vision", HIY "\n你的眼前突然出現一團耀眼的光芒，光芒中浮現出一個人影！\n\n" NOR,
		environment(ob), ({ me }) );
}

