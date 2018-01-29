// put.c

inherit F_CLEAN_UP;

int do_put(object me, object obj, object dest);

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	string target, item;
	object obj, dest, *inv, obj2;
	int i, amount;

	if(!arg) return notify_fail("你要將什麼東西放進哪裏？\n");

	if( sscanf(arg, "%s in %s", item, target)!=2 )
		return notify_fail("你要給誰什麼東西？\n");

	dest = present(target, me);
	if( !dest || living(dest) ) dest = present(target, environment(me));
	if( !dest || living(dest) )
		return notify_fail("這裏沒有這樣東西。\n");

	if(sscanf(item, "%d %s", amount, item)==2) {
		if( !objectp(obj = present(item, me)) )
			return notify_fail("你身上沒有這樣東西。\n");
		if( !obj->query_amount() )
			return notify_fail( obj->name() + "不能被分開。\n");
		if( amount < 1 )
			return notify_fail("東西的數量至少是一個。\n");
		if( amount > obj->query_amount() )
			return notify_fail("你沒有那麼多的" + obj->name() + "。\n");
		else if( amount == (int)obj->query_amount() )
			return do_put(me, obj, dest);
		else {
			obj->set_amount( (int)obj->query_amount() - amount );
			obj2 = new(base_name(obj));
			obj2->set_amount(amount);
			return do_put(me, obj2, dest);
		}
	}

	if(item=="all") {
		inv = all_inventory(me);
		for(i=0; i<sizeof(inv); i++)
			if( inv[i] != dest ) do_put(me, inv[i], dest);
		write("Ok.\n");
		return 1;
	}

	if(!objectp(obj = present(item, me)))
		return notify_fail("你身上沒有這樣東西。\n");
	return do_put(me, obj, dest);
}

int do_put(object me, object obj, object dest)
{
	if (obj->query("no_drop") ) 
		return notify_fail("這個東西還是小心保管的好，不必放在別處。\n");

	if( obj->move(dest) ) {
		message_vision( sprintf("$N將一%s%s放進%s。\n",
			obj->query("unit"), obj->name(), dest->name()),
			me );
		return 1;
	}
	else return 0;
}

int help(object me)
{
write(@HELP
指令格式 : put <物品名稱> in <某容器>
 
這個指令可以讓你將某樣物品放進一個容器，當然，首先你要擁有這樣物品。
 
HELP
    );
    return 1;
}
