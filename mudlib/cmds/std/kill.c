// kill.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object obj;
	string *killer, callname;

	if( environment(me)->query("no_fight") )
		return notify_fail("這裏不準戰鬥。\n");

	if( !arg )
		return notify_fail("你想殺誰？\n");

	if(!objectp(obj = present(arg, environment(me))))
		return notify_fail("這裏沒有這個人。\n");

	if( !obj->is_character() || obj->is_corpse() )
		return notify_fail("看清楚一點，那並不是活物。\n");

	if(obj==me)
		return notify_fail("用 suicide 指令會比較快:P。\n");

	callname = RANK_D->query_rude(obj);

	message_vision("\n$N對著$n喝道：「" 
		+ callname + "！今日不是你死就是我活！」\n\n", me, obj);

	me->kill_ob(obj);
	if( !userp(obj) )
		obj->kill_ob(me);
	else {
		obj->fight_ob(me);
		tell_object(obj, HIR "如果你要和" + me->name() 
			+ "性命相搏，請你也對這個人下一次 kill 指令。\n" NOR);
	}

	return 1;
}
int help(object me)
{
  write(@HELP
指令格式 : kill <人物>
 
這個指令讓你主動開始攻擊一個人物，並且□試殺死對方，kill 和 fight 最大的
不同在於雙方將會真刀實槍地打鬥，也就是說，會真的受傷。由於 kill 只需單方
面一廂情願就可以成立，因此你對任何人使用 kill 指令都會開始戰鬥，通常如果
對方是 NPC 的話，他們也會同樣對你使用 kill。

當有人對你使用 kill 指令時會出現紅色的字樣警告你，對於一個玩家而言，如果
你沒有對一名敵人使用過 kill 指令，就不會將對方真的打傷或殺死( 使用法術除
外)。

其他相關指令: fight

有關 fight 跟 kill 的區分請看 'help combat'.
HELP
    );
    return 1;
}
 
