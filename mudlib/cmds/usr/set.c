// set.c
 
#define MAX_ENV_VARS	20
 
inherit F_CLEAN_UP;
 
int help();
 
int main(object me, string arg)
{
    int i;
    string term, *terms, *wiz_only;
	mixed data;
	mapping env;
 
    wiz_only = ({"invisibility", "immortal"});
 
	if( me != this_player(1) ) return 0;
 
	env = me->query("env");
 
	if( !arg || arg=="" ) {
		write("你目前設定的環境變數有：\n");
		if( !mapp(env) || !sizeof(env) )
			write("\t沒有設定任何環境變數。\n");
		else {
			terms = keys(env);
			for(i=0; i<sizeof(terms); i++)
				printf("%-20s  %O\n", terms[i], env[terms[i]]);
		}
		return 1;
	}
 
	if( sscanf(arg, "%s %s", term, data)!=2 ) {
		term = arg;
		data = "YES";
	}
 
	if( term && term!="" ) {
		if( mapp(env) && undefinedp(env[term]) && sizeof(env) >= MAX_ENV_VARS )
			return notify_fail("你設的環境變數太多了，請先用 unset 刪掉幾個吧。\n");
		sscanf(data, "%d", data);
        if((wiz_level(me) == 0) && (member_array(term, wiz_only) != -1))
            return notify_fail("只有巫師能用這個設定。\n");
        me->set("env/" + term, data);
		printf("設定環境變數：%s = %O\n", term, data);
		return 1;
	}
	return help();
}
 
int help()
{
	write(@TEXT
指令格式：set <變數名> [<變數值>]
 
這個指令讓你設定一些環境變數，不加參數時會顯示你目前設定的環境變數，不指定
變數值，則內定值爲 "YES"。
 
取消變數設定請用 unset 指令。
 
至於有哪些環境變數可以設定，請見 help settings。
TEXT
	);
	return 1;
}
