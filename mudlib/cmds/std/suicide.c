// suicide.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	if( me->is_busy() )
		return notify_fail("你上一個動作還沒完成。\n");

	if( !arg ) {
		write("You commit suicide.\n");
		return 1;
	}

	if( arg!="-f" ) 
		return notify_fail("自殺有兩種，您是要永遠死掉還是重新投胎？\n");

	write(
		"如果您選擇永遠死掉的自殺方式，這個人物的資料就永遠刪除了，請務必\n"
		"考慮清楚，確定的話請輸入您的密碼：");
	input_to("check_password", 1, me, 1);
	return 1;
}

void check_password(string passwd, object me, int forever)
{
	object link_ob;
	string old_pass;

	link_ob = me->query_temp("link_ob");
	old_pass = link_ob->query("password");
	if( crypt(passwd, old_pass)!=old_pass ) {
		write("密碼錯誤！\n");
		return;
	}

	if (forever) {
		tell_object( me,
			HIR "\n\n你決定要自殺了，如果三分鐘內不後悔，就真的永別了。\n\n\n" NOR);
		me->set_temp("suicide_countdown", 10);
		me->start_busy( (: this_object(), "slow_suicide" :) );
	}
}

int slow_suicide(object me)
{
	object link_ob;
	int stage;

	stage = me->query_temp("suicide_countdown");
	me->add_temp("suicide_countdown", -1);
	if( stage > 1 ) {
		if( stage%5 == 0 )
			tell_object(me, HIR "你還有 " + stage + " 秒的時間可以後悔。\n" NOR);
		return 1;
	}

	link_ob = me->query_temp("link_ob");
	if( !link_ob ) return 0;

	log_file("static/SUICIDE",
		sprintf("%s commits a suicide on %s\n", geteuid(me), ctime(time())) );

	seteuid(getuid());
	rm( link_ob->query_save_file() + SAVE_EXTENSION );
	rm( me->query_save_file() + SAVE_EXTENSION );
		write("好吧，永別了:)。\n");
	tell_room(environment(me), me->name() +
		"自殺了，以後你再也看不到這個人了。\n", ({me}));
	destruct(me);
	return 0;
}

int help (object me)
{
        write(@HELP
指令格式: suicide [-f]
 
如果因爲某種原因你不想活了, 你可以選擇自殺.
自殺分兩種:
 
suicide    : 重新投胎
suicide -f : 永遠的除去玩家資料, 系統會要求你
             輸入密碼以確認身份.
 
請慎重選擇 :)
 
HELP
);
        return 1;
}
