// get.c

#include <ansi.h>

inherit F_CLEAN_UP;

int do_get(object me, object ob);

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	string from, item;
	object obj, *inv, env, obj2;
	int i, amount;

	if( !arg ) return notify_fail("你要撿起什麼東西？\n");
	if( me->is_busy() )
		return notify_fail("你上一個動作還沒有完成！\n");

	// Check if a container is specified.
	if( sscanf(arg, "%s from %s", arg, from)==2 ) {
		env = present(from, me);
		if(!env) env = present(from, environment(me));
		if(!env) return notify_fail("你找不到 " + from + " 這樣東西。\n");
		if(living(env) && (wiz_level(me) <= wiz_level(env)))
			return notify_fail("你的巫師等級必須比對方高，才能搜身。\n");
	} else env = environment(me);

	// Check if a certain amount is specified.
	if(sscanf(arg, "%d %s", amount, item)==2) {
		if( !objectp(obj = present(item, env)) )
			return notify_fail("這裏沒有這樣東西。\n");
		if( !obj->query_amount() )
			return notify_fail( obj->name() + "不能被分開拿走。\n");
		if( amount < 1 )
			return notify_fail("東西的個數至少是一個。\n");
		if( amount > obj->query_amount() )
			return notify_fail("這裏沒有那麼多的" + obj->name() + "。\n");
		else if( amount == (int)obj->query_amount() ) {
			return do_get(me, obj);
		} else {
			obj->set_amount( (int)obj->query_amount() - amount );
			obj2 = new(base_name(obj));
			obj2->move(env);			// For containers.
			obj2->set_amount(amount);
			// Counting precise amount costs more time.
			if( me->is_fighting() ) me->start_busy(3);
			return do_get(me, obj);
		}
	}

	// Check if we are makeing a quick get.
	if(arg=="all") {
		if( me->is_fighting() )	return notify_fail("你還在戰鬥中！只能一次拿一樣。\n");
		if( !env->query_max_encumbrance() )	return notify_fail("那不是容器。\n");

		inv = all_inventory(env);
		if( !sizeof(inv) )
			return notify_fail("那裏面沒有任何東西。\n");

		for(i=0; i<sizeof(inv); i++) {
			if( inv[i]->is_character() || inv[i]->query("no_get") ) continue;
			do_get(me, inv[i]);
		}
		write("Ok。\n");
		return 1;
	}

	if( !objectp(obj = present(arg, env)) || living(obj) )
		return notify_fail("你附近沒有這樣東西。\n");

	if( obj->query("no_get") && !wizardp(me) )
		return notify_fail("這個東西拿不起來。\n");
	
	return do_get(me, obj);
}
	
int do_get(object me, object obj)
{
	object old_env, *enemy;
	int equipped;

	if( !obj ) return 0;
	old_env = environment(obj);

	if( obj->is_character() ) {
		if( living(obj) ) return 0;
		//	if( !userp(obj) && !obj->is_corpse() )
		//		return notify_fail("你只能揹負其他玩家的身體。\n");
		// If we try to save someone from combat, take the risk :P
	} else {
		if( obj->query("no_get") && !wizardp(me) ) return 0;
	}

	if( obj->query("equipped") ) equipped = 1;
	if( obj->move(me) ) {
		if( me->is_fighting() ) me->start_busy(1);
		if( obj->is_character() )
			message_vision( "$N將$n扶了起來背在背上。\n", me, obj );
		else
			message_vision( sprintf("$N%s一%s$n。\n", 
				old_env==environment(me)? "撿起":
					(old_env->is_character() ?
						"從" + old_env->name() + "身上" + (equipped? "除下" : "搜出"):
						"從" + old_env->name() + "中拿出"),
				obj->query("unit")), me, obj );
		return 1;
	}
	else return 0;
}

int help(object me)
{
	write(@HELP
指令格式 : get <物品名稱> [from <容器名>]
 
這個指令可以讓你撿起地上或容器內的某樣物品.
 
HELP
    );
    return 1;
}
 
