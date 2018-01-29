// reply.c

#include <ansi.h>
#include <net/dns.h>

inherit F_CLEAN_UP;

int help(object me);

int main(object me, string arg)
{
	string target, mud;
	object obj;

	if( !arg || arg=="" )
		return notify_fail("你要回答什麼？\n");

	if( !stringp(target = me->query_temp("reply")) )
		return notify_fail("剛纔沒有人和你說過話。\n");

	if( sscanf(target, "%s@%s", target, mud)==2 ) {
		GTELL->send_gtell(lower_case(mud), lower_case(target), me, arg);
		write("網路訊息已送出，可能要稍候才能得到迴應。\n");
		return 1;
	}

	obj = find_player(target);
	if( !obj )
		return notify_fail("剛纔和你說話的人現在無法聽見你，或者已經離開遊戲了。\n");
	write(GRN "你回答" + obj->name(1) + "：" + arg + "\n" NOR);
	tell_object(obj, sprintf(GRN"%s回答你：%s\n"NOR,
		me->name(1), arg ));

	obj->set_temp("reply", me->query("id"));
	return 1;
}

int help(object me)
{
	write(@HELP
指令格式：reply <訊息>

你可以用這個指令和剛纔用 tell 和你說話的使用者說話。

see also : tell
HELP
	);
	return 1;
}
