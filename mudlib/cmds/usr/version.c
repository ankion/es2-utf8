// version.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	write(__VERSION__+"\n");
	return 1;
}
int help(object me)
{
  write(@HELP
指令格式 : version
 
這個指令會顯示遊戲目前所用的 MudOS driver 版本.
 
HELP
    );
    return 1;
}
 
