// enchant.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	int pts;

	if( !arg || !sscanf(arg, "%d", pts) ) 
		return notify_fail("指令格式：enchant <靈力點數>\n");

	if( pts > ((int)me->query("atman")/50+1) )
		return notify_fail("你的靈力不足，發不出那麼強的威力。\n");

	if( pts < 0 ) return notify_fail("靈力點數必須是正數。\n");	
	me->set("mana_factor", pts);
	write("Ok.\n");
	return 1;
}

int help (object me)
{
	write(@HELP
指令格式: enchant <靈力點數>
 
這個指令讓你設定使用魔法武器時要用來導引武器魔力所用的靈力強度。
不同的武器所需的靈力不同，威力也不一樣，有些魔力強大的武器如果使用者
無法發出足以駕馭它的靈力，就有可能產生可怕的後果。

HELP
	);
	return 1;
}
