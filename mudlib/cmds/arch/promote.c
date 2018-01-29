// promote.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob;
	string old_status, new_status;
	int my_level, ob_level, level;

	if( me!=this_player(1) ) return 0;

	if( !arg || sscanf(arg, "%s %s", arg, new_status)!=2 )
		return notify_fail("指令格式：promote <使用者> <等級>\n");

	if( wiz_level(new_status) < 0 ) return notify_fail("沒有這種等級。\n");

	if( !objectp(ob = present(arg, environment(me))) 
	||	!userp(ob) )
		return notify_fail("你只能改變使用者的權限。\n");

	if( wiz_level(me) < wiz_level(new_status) )
		return notify_fail("你沒有這種權力。\n");

	old_status = wizhood(ob);

	seteuid(getuid());
	if( !(SECURITY_D->set_status(ob, new_status)) )
		return notify_fail("修改失敗。\n");

	message_vision("$N將$n的權限從 " + old_status + " 改爲 " + new_status + " 。\n", me, ob);
	seteuid(getuid());
	ob->setup();

	return 1;
}

int help(object me)
{
write(@HELP
指令格式 : promote <某人> (權限等級)

用來提升權限等級, (player) (immortal) (apprentice) (wizard)
(arch) (admin)
一個 admin 能提升權限至任何等級, 而 arch 只能提升至 arch。
HELP
    );
    return 1;
}
