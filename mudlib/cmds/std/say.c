// say.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	if (!arg) {
		write("你自言自語不知道在說些什麼。\n");
		message("sound", me->name() + "自言自語不知道在說些什麼。\n",
			environment(me), me);
		return 1;
	}
	if( (int)me->query("kee") < (int)me->query("max_kee") / 5 ) {
		arg = replace_string(arg, " ", " ... ") + " ...";
	}

	write( CYN "你說道：" + arg + "\n" NOR);
	message("sound", CYN + me->name() + "說道：" +  arg + "\n" NOR,
		environment(me), me);

	// The mudlib interface of say
	all_inventory(environment(me))->relay_say(me, arg);

	return 1;
}

int help (object me)
{
	write(@HELP
指令格式: say <訊息>
 
說話，所有跟你在同一個房間的人都會聽到你說的話。
 
注: 本指令可用 ' 取代.
 
HELP
	);
	return 1;
}
