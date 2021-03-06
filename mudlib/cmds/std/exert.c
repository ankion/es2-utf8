// exert.c

#include <skill.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        string force;
        //int result;
	int skill ;
        
        seteuid(getuid());

        if( me->is_busy() )
                return notify_fail("( 
你上一個動作還沒有完成，不能施用內功。)\n");

        if( !arg ) return notify_fail("你要用內功做什麼？\n");

        if( stringp(force = me->query_skill_mapped("force")) ) {
                notify_fail("你所學的內功中沒有這種功能。\n");
                if( SKILL_D(force)->exert_function(me, arg) ) {
                        if( random(120) < (int)me->query_skill("force") )
                                me->improve_skill(force, 1, 1);
                        return 1;
                } else if( SKILL_D("force")->exert_function(me, arg) ) {
			skill = (int)me->query_skill("force",1) * 4 ;
                        if( random(skill) < (int)me->query_skill("force", 1) )
                                me->improve_skill("force", 1, 0);
                        return 1;
                }
                return 0;
        }

        return notify_fail("你請先用 enable 指令選擇你要使用的內功。\n");
}

int help (object me)
{
        write(@HELP
指令格式：exert <功能名稱> [<施用對象>]

用內力進行一些特異功能，你必需要指定<功能名稱>，<施用對象>則可有可無。
在你使用某一種內功的特異功能之前，你必須先用 enable 指令來指定你要使用
的內功。

請參考 help force 可得知一些大部分內功都有的功能，至於你所用的內功到底
有沒有該功能，試一試或參考其他說明便知。

注：如果你改變自己的內功，你原本蓄積的內力並不能直接轉換過去，必須
    從 0 開始。
 
HELP
        );
        return 1;
}
 
