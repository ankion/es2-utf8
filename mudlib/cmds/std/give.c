// give.c

inherit F_CLEAN_UP;

int do_give(object me, object obj, object who);

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	string target, item;
	object obj, who, *inv, obj2;
	int i, amount;

	if(!arg) return notify_fail("你要給誰什麼東西？\n");

	if( sscanf(arg, "%s to %s", item, target)==2
	|| sscanf(arg, "%s %s", target, item)==2 );
	else return notify_fail("你要給誰什麼東西？\n");

	if(!objectp(who = present(target, environment(me))) || !living(who))
		return notify_fail("這裏沒有這個人。\n");

	if(sscanf(item, "%d %s", amount, item)==2) {
		if( !objectp(obj = present(item, me)) )	
			return notify_fail("你身上沒有這樣東西。\n");
		if( obj->query("no_drop") && !wizardp(me))
			return notify_fail("這樣東西不能隨便給人。\n");
		if( !obj->query_amount() )	
			return notify_fail( obj->name() + "不能被分開給人。\n");
		if( amount < 1 )
			return notify_fail("東西的數量至少是一個。\n");
		if( amount > obj->query_amount() ) 
			return notify_fail("你沒有那麼多的" + obj->name() + "。\n");
		else if( amount == (int)obj->query_amount() )
			return do_give(me, obj, who);
		else {
			obj->set_amount( (int)obj->query_amount() - amount );
			obj2 = new(base_name(obj));
			obj2->set_amount(amount);
			return do_give(me, obj2, who);
		}
	}

	if(arg=="all") {
		inv = all_inventory(me);
		for(i=0; i<sizeof(inv); i++) {
			do_give(me, inv[i], who);
		}
		write("Ok.\n");
		return 1;
	}

	if(!objectp(obj = present(item, me)))
		return notify_fail("你身上沒有這樣東西。\n");
	return do_give(me, obj, who);
}

int do_give(object me, object obj, object who)
{
	if( obj->query("no_drop") && !wizardp(me) )
		return notify_fail("這樣東西不能隨便給人。\n");

	if( !interactive(who) && !who->accept_object(me, obj) )
		return notify_fail("你只能把東西送給其他玩家操縱的人物。\n");

	if( !userp(who) && obj->value() ) {
		message_vision("$N拿出" + obj->short() + "給$n。\n", me, who);
		destruct(obj);
		return 1;
	} else if( obj->move(who) ) {
		printf("你給%s一%s%s。\n", who->name(), obj->query("unit"),
			obj->name());
		message("vision", sprintf("%s給你一%s%s。\n", me->name(),
			obj->query("unit"), obj->name()), who );
		message("vision", sprintf("%s給%s一%s%s。\n", me->name(), who->name(),
			obj->query("unit"), obj->name()), environment(me), ({me, who}) );
		return 1;
	}
	else return 0;
}
int help(object me)
{
write(@HELP
指令格式 : give <物品名稱> to <某人>
      或 : give <某人> <物品名稱>
 
這個指令可以讓你將某樣物品給別人, 當然, 首先你要擁有這樣物品.
 
HELP
    );
    return 1;
}
