// unwield.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob/*, *inv*/;
	string str;
	//int i;

	if( !arg ) return notify_fail("你要脫掉什麼？\n");

	if( !objectp(ob = present(arg, me)) )
		return notify_fail("你身上沒有這樣東西。\n");

	if( (string)ob->query("equipped")!="wielded" )
		return notify_fail("你並沒有裝備這樣東西作爲武器。\n");

	if( ob->unequip() ) {
		if( !stringp(str = ob->query("unwield_msg")) )
			str = "$N放下手中的$n。\n";
		message_vision(str, me, ob);
		return 1;
	} else
		return 0;
}

int help(object me)
{
  write(@HELP
指令格式 : unwield <物品名>
 
這個指令讓你放下手中的武器。
 
HELP
    );
    return 1;
}
 
