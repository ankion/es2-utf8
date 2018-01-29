// home.c

#include "/doc/help.h"

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string msg;

	if( file_size(user_path(geteuid(me)) + "workroom.c") <= 0 )
		return notify_fail("你沒有自己的工作室。\n");

	if( stringp(msg = me->query("env/msg_home")) )
		message_vision(msg + "\n", me);
	me->move(user_path(geteuid(me)) + "workroom");
	return 1;
}

int help(object me)
{
  write(@HELP
指令格式 : home

利用此一指令可直接回到自己的工作室。
如果你有 'msg_home' 這個設定, 則在場的人都會看到那個訊息.
HELP
    );
    return 1;
}
