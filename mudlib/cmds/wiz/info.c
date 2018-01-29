// info.c

inherit F_CLEAN_UP;

int help(object me);

int main(object me, string arg)
{
	object obj;
	string str;

	if (!arg) return help(me);

	seteuid(geteuid(me));

	if( arg=="me" ) obj = me;
	else if( arg=="my link" ) obj = me->query_temp("link_ob");
	else {
		obj = present(arg, me);
		if (!obj) obj = present(arg, environment(me));
		if (!obj) obj = find_object( resolve_path(me->query("cwd"), arg) );
		if (!obj) return notify_fail("沒有這樣物件....。\n");
	}

	printf("物件 [%O]\n-----------------------------------------------------\n", obj);
	write("檔案：\t\t" + base_name(obj) + ".c\n");
	write("領域：\t\t" + domain_file(base_name(obj)) + "\n");
	write("作者：\t\t" + author_file(base_name(obj)) + "\n");
	write("權限：\t\tuid = " + getuid(obj) + ", euid = " + geteuid(obj) + "\n");
	write("等級：\t\t" + wizhood(obj) + "\n");
	write("使用記憶體：\t" + memory_info(obj) + "\n");
	str = "";
	if( living(obj) ) 		str += "生物 ";
	if( userp(obj) )		str += "使用者 ";
	if( interactive(obj) )	str += "線上 ";
	if( wizardp(obj) ) 		str += "巫師 ";
	if( clonep(obj) ) 		str += "複製 ";
	if( virtualp(obj) ) 	str += "虛擬 ";
	if( query_heart_beat(obj) ) str += "心跳:" + query_heart_beat(obj) + " ";
	write("屬性：\t\t" + str + "\n");
	write("複製個數：\t" + sizeof(children(base_name(obj)+".c")) + "\n");
	write("參考連結：\t" + refs(obj) + "\n");

	return 1;
}

int help(object me)
{
  write(@HELP
指令格式 : info <物件之名稱或檔名>

利用此一指令可得知一些有關該物件的資訊。
HELP
    );
    return 1;
}
