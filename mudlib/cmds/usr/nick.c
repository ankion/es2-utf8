// nick.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	if( !arg ) return notify_fail("你要替自己取什麼綽號？\n");
        if ( arg == "none" ) {
             me->set("nickname",0);
             write("OK!\n");
             return 1 ;
        }
	if( strlen(arg) > 50 )
		return notify_fail("你的綽號太長了，想一個短一點的、響亮一點的。\n");

	arg = replace_string(arg, "$BLK$", BLK);
	arg = replace_string(arg, "$RED$", RED);
	arg = replace_string(arg, "$GRN$", GRN);
	arg = replace_string(arg, "$YEL$", YEL);
	arg = replace_string(arg, "$BLU$", BLU);
	arg = replace_string(arg, "$MAG$", MAG);
	arg = replace_string(arg, "$CYN$", CYN);
	arg = replace_string(arg, "$WHT$", WHT);
	arg = replace_string(arg, "$HIR$", HIR);
	arg = replace_string(arg, "$HIG$", HIG);
	arg = replace_string(arg, "$HIY$", HIY);
	arg = replace_string(arg, "$HIB$", HIB);
	arg = replace_string(arg, "$HIM$", HIM);
	arg = replace_string(arg, "$HIC$", HIC);
	arg = replace_string(arg, "$HIW$", HIW);
	arg = replace_string(arg, "$NOR$", NOR);

	me->set("nickname", arg + NOR);
	write("Ok.\n");
	return 1;
}
int help(object me)
{
        write(@HELP
指令格式 : nick <外號, 綽號>
 
這個指令可以讓你爲自己取一個響亮的名號或頭銜，你如果希望在綽號中
使用 ANSI 的控制字元改變顏色，可以用以下的控制字串：

$BLK$ - 黑色		$NOR$ - 恢復正常顏色
$RED$ - 紅色		$HIR$ - 亮紅色
$GRN$ - 綠色		$HIG$ - 亮綠色
$YEL$ - 土黃色		$HIY$ - 黃色
$BLU$ - 深藍色		$HIB$ - 藍色
$MAG$ - 淺紫色		$HIM$ - 粉紅色
$CYN$ - 藍綠色		$HIC$ - 天青色
$WHT$ - 淺灰色		$HIW$ - 白色
 
其中系統自動會在字串尾端加一個 $NOR$。

HELP
        );
        return 1;
}
