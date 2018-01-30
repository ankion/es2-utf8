// perform.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        object weapon;
        string martial, skill;
        //int result;
        
        seteuid(getuid());

        if( me->is_busy() )
                return notify_fail("( 
你上一個動作還沒有完成，不能施用外功。)\n");

        if( !arg ) return notify_fail("你要用外功做什麼？\n");

        if( sscanf(arg, "%s.%s", martial, arg)!=2 ) {
                if( weapon = me->query_temp("weapon") )
                        martial = weapon->query("skill_type");
                else
                        martial = "unarmed";
        }

        if( stringp(skill = me->query_skill_mapped(martial)) ) {
                notify_fail("你所使用的外功中沒有這種功能。\n");
                if( SKILL_D(skill)->perform_action(me, arg) ) {
                        if( random(120) < (int)me->query_skill(skill) )
                                me->improve_skill(skill, 1, 1);
                        return 1;
                } else if( SKILL_D(martial)->perform_action(me, arg) ) {
                        if( random(120) < (int)me->query_skill(martial, 1) )
                                me->improve_skill(martial, 1, 1);
                        return 1;
                }
                return 0;
        }

        return notify_fail("你請先用 enable 指令選擇你要使用的外功。\n");
}

int help (object me)
{
        write(@HELP
指令格式：perfrom [<武功種類>.]<招式名稱> [<施用對象>]

如果你所學的外功(拳腳、劍法、刀法....)有一些特殊的攻擊方式或招式，可以
用這個指令來使用，你必須先用 enable 指令指定你使用的武功，不指定武功種
類時，空手的外功是指你的拳腳功夫，使用武器時則是兵刃的武功。

若是你的外功中有種類不同，但是招式名稱相同的，或者不屬於拳腳跟武器技能
的武功(如輕功)，可以用 <武功>.<招式>  的方式指定，如：

perform sword.powerfocus 
perform move.reflexion

換句話說，只要是 enable 中的武功有特殊招式的，都可以用這個指令使用。
HELP
        );
        return 1;
}
 
