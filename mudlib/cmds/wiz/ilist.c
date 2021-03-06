// ilist.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob;

	if( !arg ) return notify_fail("指令格式：ilist <物件或檔名>\n");

	ob = present(arg, me);
	if( !ob ) ob = present(arg, environment(me));
	if( !ob ) ob = find_object(resolve_path(me->query("cwd"), arg));
	if( !ob ) return notify_fail("沒有這樣物件或這樣物件沒有被載入。\n");

	printf("%O直接或間接繼承以下檔案：\n    %s\n", ob,
		implode(deep_inherit_list(ob), "\n    "));
	return 1;
}

int help (object me)
{
        write(@HELP
指令格式: ilist <物件或檔名>
 
列出一個物件所繼承的所有物件。
 
HELP
);
        return 1;
}
 
