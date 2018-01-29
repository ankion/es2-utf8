// cd.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string dir;

	if( !arg )
		arg = user_path(me->query("id"));
	dir = resolve_path(me->query("cwd"), arg);
	if(file_size(dir)!=-2) return notify_fail("沒有這個目錄。\n");

	if(dir[strlen(dir)-1]!='/') dir += "/";
	me->set("cwd", dir);
	write(dir + "\n");
	return 1;	
}

int help(object me)
{
	write(@HELP
指令格式 : cd <子目錄名>, cd .. , and cd

將目前參考的目錄移至指定的子目錄或回到上一主目錄; 亦可直接回到自己工作目錄。
HELP
	);
	return 1;
}
