// emote.c (Mon  09-04-95)

#include <ansi.h>
inherit F_CLEAN_UP;
 
int main(object me, string str)
{
    if (!str) {
        write(CYN"你看起來表情豐富。\n"NOR);
	message("channel:chat", BLU +"【閒聊】"+(string)me->name()+ "\077\064\106\160\100\064\061\155\107\151\067\141\070\073\041\043\n"+ NOR , users());   
     //   tell_room(environment(me), CYN+(string)me->name()+
//		"看起來表情豐富。\n" +NOR, me);
        return 1;
    }
    write(CYN"你"+str+"\n"NOR);
 //   tell_room(environment(me), CYN+(wizardp(me)? "":"->")+(string)me->name()+
  //      str+"\n"+NOR, me);
  	 message("channel:chat",  BLU +"【閒聊】"+(string)me->name()+str +"\n"+NOR, users());
	 return 1;
}
 
int help(object me)
{
	write(@HELP
指令格式: emote <動作詞>

這個指令可以讓你表達一個系統沒有預設的動作詞, 系統會將你所輸入
的文字加上你的姓名後顯示給所有在同一個地方的生物看. 爲了避免造
成困擾, 玩家所輸入的詞句前面會加上 -> 以供區別. (巫師則不在此
限.)

□例: emote 坐了下來。
你會看見: 你坐了下來。
其他人會看到: ->包子坐了下來。

其中, 包子就是你的名字.

相關指令: semote
HELP
	);
        return 1;
}
