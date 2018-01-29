// goto.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	int goto_inventory = 0;
	object obj;
	string msg;

	if( !arg ) return notify_fail("你要去哪裏？\n");

	if( sscanf(arg, "-i %s", arg) ) goto_inventory = 1;

	if( !arg ) return notify_fail("你要去哪裏？\n");

	obj = find_player(arg);
	if(!obj) obj = find_living(arg);
	if(!obj || !me->visible(obj)) {
		arg = resolve_path(me->query("cwd"), arg);
		if( !sscanf(arg, "%*s.c") ) arg += ".c";
		if( !(obj = find_object(arg)) ) {
			if( file_size(arg)>=0 )
				return me->move(arg);
			return notify_fail("沒有這個玩家、生物、或地方。\n");
		}
	}

	if(!goto_inventory && environment(obj))
		obj = environment(obj);

	if( !obj ) return notify_fail("這個物件沒有環境可以 goto。\n");

    if( stringp(msg = me->query("env/msg_mout")) )
        message_vision(msg+"\n", me);
	else
		message_vision("只見一陣煙霧過後，$N的身影已經不見了。\n", me);

	me->move(obj);

	if( stringp(msg = me->query("env/msg_min")) )
        message_vision(msg+"\n", me);
	else
		message_vision("$N的身影突然出現在一陣煙霧之中。\n", me);

	return 1;
}

int help(object me)
{
write(@HELP
指令格式 : goto [-i] <目標>
 
這個指令會將你傳送到指定的目標. 目標可以是一個living 或房間
的檔名. 如果目標是living , 你會被移到跟那個人同樣的環境.
如果有加上 -i 參數且目標是 living, 則你會被移到該 living 的
的 inventory 中.
 
HELP
    );
    return 1;
}
