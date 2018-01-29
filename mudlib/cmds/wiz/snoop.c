// snoop.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob;

	if( !arg ) {
		if( objectp(ob = query_snooping(me)) )
			write("你現在正在監聽" + ob->query("name") + "所收到的訊息。\n");
		return 1;
	} else if( arg=="none" ) {
		if( objectp(ob = query_snooping(me))
		&&	wiz_level(ob) >= wiz_level(me) )
			tell_object(ob, HIW + me->name(1) + "停止監聽你所收到的訊息。\n" NOR);
		snoop(me);
		write("Ok.\n");
		return 1;
	}

	ob = find_player(arg);
	if(!ob) ob = find_living(arg);
	if(!ob || !me->visible(ob)) return notify_fail("沒有這個人。\n");

	if( wizhood(me) != "(admin)"
	&&	wiz_level(me) <= wiz_level(ob) )
		return notify_fail("你沒有監聽" + ob->name() + "所收聽訊息的權利。\n");

	if( me==ob ) return notify_fail("請用 snoop none 解除監聽。\n");
		
	snoop(me, ob);
	write("你現在開始竊聽" + ob->name(1) + "所收到的訊息。\n");
	if( userp(ob) ) log_file("SNOOP_PLAYER",
		sprintf("%s(%s) snoops %s on %s.\n", me->name(1), geteuid(me), ob->name(1),
			ctime(time()) ) );
	if( wizardp(ob) && wizhood(me) != "(admin)")
		tell_object(ob, HIW + me->name(1) + "開始監聽你所收到的訊息。\n" + NOR);

	return 1;
}

int help()
{
	write(@TEXT
指令格式：snoop <某人>|none

監聽其他使用者所收聽的訊息，snoop none 則取消監聽。
TEXT
	);
	return 1;
}
