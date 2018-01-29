// cast.c

#include <skill.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string spells, spl, trg;
	object target;
	
	seteuid(getuid());

	if( me->is_busy() )
		return notify_fail("( 你上一個動作還沒有完成，不能唸咒文。)\n");

	if( environment(me)->query("no_magic") )
		return notify_fail("這裏不準唸咒文。\n");

	if( !arg ) return notify_fail("指令格式：cast <法術> [on <目標>]\n");
	if( sscanf(arg, "%s on %s", spl, trg)==2 ) {
		target = present(trg, environment(me));
		if( !target ) target = present(trg, me);
		if( !target ) return notify_fail("這裏沒有 " + trg + "。\n");
	} else {
		spl = arg;
		target = 0;
	}

	spl = replace_string( spl, " ", "_");

	if( stringp(spells = me->query_skill_mapped("spells")) )
		return (int)SKILL_D(spells)->cast_spell(me, spl, target);
		
	return notify_fail("你請先用 enable 指令選擇你要使用的咒文系。\n");
}

int help (object me)
{
        write(@HELP
指令格式：cast <咒文名稱> [on <施咒對象>]
 
施法，你必需要指定<咒文名稱>，<施咒對象>則可有可無。
在你使用某一個咒文之前，你必須先用 enable 指令來指定你要使用的咒文系。
 
注：如果你改變自己的咒文系，你原本蓄積的法力並不能直接轉換過去，必須
    從 0 開始。
 
HELP
        );
        return 1;
}
