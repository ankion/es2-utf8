// scribe.c

#include <skill.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string spells, name, ob_name, opp;
	object ob;

	// We might need to load new objects.
	seteuid(getuid());

	if( me->is_fighting() )	return notify_fail("戰鬥時不能畫符！\n");
	if( (int)me->query("sen") < 30 )
		return notify_fail("你的精神太差了，無法畫符。\n");

	if( !arg
	||	sscanf(arg, "%s on %s for %s", name, ob_name, opp)!= 3 )
		return notify_fail("指令格式：scribe <符咒> on <物品>\n");

	if( !objectp(ob = present(ob_name, me)) )
		return notify_fail("你身上沒有這樣東西。\n");

	if( stringp(spells = me->query_skill_mapped("spells")) ) {
//		notify_fail("你所學的法術沒有這種符。\n");
//		if( SKILL_D(spells)->scribe_spell(me, ob, name) ) {
		if( (SKILL_D(spells)->scribe_spell_file(name))->scribe(me, ob, opp) ) {
			me->receive_wound("kee", 1);
			me->receive_damage("sen", 30);
			return 1;
		}
		return 0;
	} else 
		return notify_fail("你請先用 enable 指令選擇你要使用的咒文系。\n");

	return 1;
}

int help (object me)
{
        write(@HELP
指令格式：scribe <符咒名稱> on <物品名稱> [for <對象>]

在畫符用的桃符紙(paper seal)或其他物品上畫符，即使是相同的符咒，畫在不
同的物品上也有可能有不同的效果。

在你畫符之前，你必須先用 enable 指令來指定你要使用的咒文系。

注：畫符會消耗若干氣(要咬破手指用鮮血畫)與神，畫成的符咒可以用 attach
    指令將它貼在目標物身上。
 
HELP
        );
        return 1;
}
