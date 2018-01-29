// rm.c

#include "/doc/help.h"

inherit F_CLEAN_UP;
int help(object me);

int main(object me, string file)
{
	seteuid(geteuid(me));
    if (!file) return notify_fail("你要刪除那個檔案?\n");
	if( rm(resolve_path(me->query("cwd"), file)) )
		write("Ok.\n");
	else
		write("你沒有刪除這個檔案的權利。\n");
	return 1;
}

int help(object me)
{
  write(@HELP
指令格式 : rm <檔名>

此指令可讓你(□)刪除有權修改的檔案。
HELP
    );
    return 1;
}
