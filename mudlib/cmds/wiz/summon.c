// summon command..

inherit F_CLEAN_UP;

int main(object me, string str)
{
	object ob;
	int i;
	if (!str) return notify_fail("<Syntax>: Summon <player id>\n");
	ob = LOGIN_D->find_body(str);
	if (!ob) return notify_fail("咦... 有這個人嗎?\n");
	// moving
	tell_room(environment(ob),"天空中伸出一隻大手把"+
	(string)ob->query("name")+"抓了起來, 然後不見了.\n", ob);
	tell_object(ob,"一隻手把你抓了起來, 你眼前一陣黑....\n");
	ob->move(environment(me));
        tell_object(me, "你把"+(string)ob->query("name")+"抓到你的面前.\n");
	tell_object(ob,".... 醒來時發現是"+(string)me->query("name")+
	"把你弄過來的.\n");
	tell_room(environment(ob),(string)ob->query("name")+"突然出現"+
	"在你眼前\n",({me,ob}));
	// ok ..
	return 1;
}

int help(object me)
{
write(@HELP
指令格式 : summon <某人>

此指令可讓你(□)將某人抓到你面前。
HELP
    );
    return 1;
}
