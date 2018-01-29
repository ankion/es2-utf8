// where.c
// 06-14-95

inherit F_CLEAN_UP;

int main(object me, string str)
{
	object ob, where, *ob_list;
	int i;

	if (!str)
		return notify_fail("指令格式：where <人物或檔名>\n"); 
	ob = find_player(str);
	if( !ob ) ob = find_living(str);
	if( !ob || !me->visible(ob)) {
		str = resolve_path(me->query("cwd"), str);
		ob_list = children(str);
		for(i=0; i<sizeof(ob_list); i++) {
			if( !ob = environment(ob_list[i]) ) continue;
			printf("%O\n", ob );
		}
		return 1;
	}
	if (!ob) return notify_fail("現在沒這個人.\n");
	where = environment(ob);
	if (!where) return notify_fail("這個人不知道在那裏耶...\n");
	printf("%s(%s)現在在%s(%s).\n",
		(string)ob->name(),
		(string)ob->query("id"),
		(string)where->query("short"),
		(string)file_name(where));
	return 1;
}

int help(object me)
{
	write(@HELP
指令格式: where <玩家的 ID>

這個指令是用來得知玩家目前所在的位置.

HELP
	);
	return 1;
}

