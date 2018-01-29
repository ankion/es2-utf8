// tell.c

#include <ansi.h>
#include <net/dns.h>

inherit F_CLEAN_UP;

int help(object me);

	void create() {seteuid(getuid());}

int main(object me, string arg)
{
	string target, msg, mud;
	object obj;

	if( !arg || sscanf(arg, "%s %s", target, msg)!=2 ) return help(me);

	if( sscanf(target, "%s@%s", target, mud)==2 ) {
		GTELL->send_gtell(mud, target, me, msg);
		write("網路訊息已送出，可能要稍候才能得到迴應。\n");
		return 1;
	}

	obj = find_player(target);
	if(!obj || !me->visible(obj)) return notify_fail("沒有這個人....。\n");

	write(GRN "你告訴" + obj->name(1) + "：" + msg + "\n" NOR);
	tell_object(obj, sprintf( GRN "%s告訴你：%s\n" NOR,
		me->name(1)+"("+me->query("id")+")", msg));

	obj->set_temp("reply", me->query("id"));
	return 1;
}

int remote_tell(string cname, string from, string mud, string to, string msg)
{
	object ob;

	if( ob = find_player(to) ) {
		if( cname )
			tell_object(ob, sprintf(HIG "%s(%s@%s)告訴你：%s\n" NOR,
				cname, capitalize(from), mud, msg ));
		else
			tell_object(ob, sprintf(HIG "%s@%s 告訴你：%s\n" NOR,
				capitalize(from), mud, msg ));
		ob->set_temp("reply", from + "@" + mud);
		return 1;
	} else
		return 0;
}

int help(object me)
{
	write(@HELP
指令格式：tell <某人> <訊息>

你可以用這個指令和其他地方的使用者說話。

其他相關指令：reply
HELP
	);
	return 1;
}
