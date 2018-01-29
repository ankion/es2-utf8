// smash.c 2-22-95
 
#include "/doc/help.h"

inherit F_CLEAN_UP;
 
int main(object me, string arg)
{
	object ob;
	string name1, name2;

	if (!arg) return notify_fail("指令格式: smash <living>\n");
	ob = present(arg, environment(me));
	if (!ob) return notify_fail("找不到這個生物.\n");
	name1 = (string)me->query("name");
	name2 = (string)ob->query("name");
	tell_room(environment(me),
	name1+"高舉雙手大喝 去死把!, 只見天上一道閃電不偏不倚地擊中"+name2+", 將之化爲一堆灰燼.\n", 
	({me, ob}));
	tell_object(ob, name1+"高舉雙手大喝 去死把!, 只見天上一道閃電不偏不倚地擊中你.\n");
	
	write("你高舉雙手大喝 去死吧! 從天上降下一道閃電將"+name2+"化作一堆灰燼.\n");
	write("哈哈哈哈哈哈... 好爽!\n");
	ob -> die();
	return 1;
}
 
int help(object me)
{
   write(@HELP
指令格式: smash <生物>
 
hehehehehe...........

HELP
   );
   return 1;
}
