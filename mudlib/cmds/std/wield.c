// wield.c

inherit F_CLEAN_UP;

int do_wield(object me, object ob);

int main(object me, string arg)
{
	object ob, *inv;
	int i, count;

	if( !arg ) return notify_fail("你要裝備什麼武器？\n");

	if(arg=="all") {
		inv = all_inventory(me);
		for(count=0, i=0; i<sizeof(inv); i++) {
			if( inv[i]->query("equipped") ) continue;
			if(do_wield(me, inv[i]) ) count ++;
		}
		write("Ok.\n");
		return 1;
	}

	if( !objectp(ob = present(arg, me)) )
		return notify_fail("你身上沒有這樣東西。\n");

	if( ob->query("equipped") )
		return notify_fail("你已經裝備著了。\n");

	return do_wield(me, ob);
}

int do_wield(object me, object ob)
{
	string str;

	if( ob->wield() ) {
		if( !stringp(str = ob->query("wield_msg")) )
			str = "$N裝備$n作武器。\n";
		message_vision(str, me, ob);
		return 1;
	} else
		return 0;
}

int help(object me)
{
	write(@HELP
指令格式：wield <裝備名稱>
 
這個指令讓你裝備某件物品作武器, 你必需要擁有這樣物品.
 
HELP
    );
    return 1;
}
