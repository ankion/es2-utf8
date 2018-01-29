// practice.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string skillname;
	int skill, skill_basic;

	seteuid(getuid());
	if( me->is_fighting() )
		return notify_fail("你已經在戰鬥中了，學一點實戰經驗吧。\n");

	if( !arg ) return (__DIR__"enable")->main(me, arg);

	if( !stringp(skillname = me->query_skill_mapped(arg)) )
		return notify_fail("你只能練習用 enable 指定的特殊技能。\n");

	skill_basic = me->query_skill(arg, 1);
	skill = me->query_skill(skillname, 1);

	if( skill < 1 )
		return notify_fail("你好像還沒「學會」這項技能吧？最好先去請教別人。\n");
	if( skill_basic < 1 )
		return notify_fail("你對這方面的技能還是一竅不通，最好從先從基本學起。\n");

	notify_fail("你現在不能練習這項技能。\n");
	if( !SKILL_D(skillname)->valid_learn(me) ) return 0;

	notify_fail("你試著練習" + to_chinese(skillname) + "，但是並沒有任何進步。\n");
	if( SKILL_D(skillname)->practice_skill(me) ) {
		me->improve_skill(skillname, skill_basic/5 +1, skill_basic > skill? 0: 1);
		write( HIY "你的" + to_chinese(skillname) + "進步了！\n" NOR);
		return 1;
	}
	else return 0;
}

int help(object me)
{
	write(@TEXT
指令格式：practice <技能種類>

這個指令讓你練習某個種類的技能，這個技能必須是經過 enable 的專業技能。

如果你對這方面的基本技能夠高，可以經由練習直接升級，而且升級的上限只跟
你基本技能的等級有關，換句話說，勤加練習是使你的所學「青出於藍勝於藍」
的唯一途徑，當然，在這之前你必須從實際運用中獲得足夠的經驗以提升你的基
本技能。
TEXT
	);
	return 1;
}
