// dest.c

#include "/doc/help.h"

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string option, target, msg;

	object obj;

	if (!arg) return notify_fail("指令格式 : dest <物件之名稱或檔名>\n" );

	if( sscanf(arg, "%s %s", option, target)!=2 ) target = arg;

	if( option == "-r" && (string)SECURITY_D->get_status(me)=="(admin)" )
		seteuid(ROOT_UID);
	else
		seteuid(geteuid(me));

	obj = find_object(target);
	if (!obj) obj = present(target, me);
	if (!obj) obj = present(target, environment(me));
	if (!obj) obj = find_object( resolve_path(me->query("cwd"), target) );
	if (!obj) return notify_fail("沒有這樣物件....。\n");

	if( environment(me)==environment(obj) )
	if( !stringp(msg = me->query("env/msg_dest")) )
		msg = "$N召喚出一個黑洞，將$n吞沒了。\n";
	else
		message_vision(msg + "\n", me, obj);

	destruct(obj);
	if(obj) write("你無法將這個物件摧毀。\n");
	else write("Ok.\n");

	return 1;
}

int help(object me)
{
	write(@HELP
指令格式 : dest [-r] <物件之名稱或檔名>

利用此一指令可將一個物件(object)或物件定義(class)從記憶體中清除，若清除物
件定義(即：指定檔名的情況下)則下一次參考到這個物件的時候會重新將它編譯。

具有 (admin) 身分的巫師可以用 -r 選項以 ROOT_UID 身分來清除被保護的物件如
使用者。

參考資料： destruct()
HELP
    );
    return 1;
}
