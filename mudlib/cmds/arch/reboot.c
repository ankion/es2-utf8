// reboot.c

#include <login.h>
#include <obj.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string wiz_status;
	object npc;

	if( me != this_player(1) ) return 0;
	
	wiz_status = SECURITY_D->get_status(me);
	if( wiz_status != "(admin)" && wiz_status != "(arch)" )
		return notify_fail("只有 (arch) 以上的巫師才能重新啓動" + MUD_NAME + "\n");

	seteuid(getuid());

	npc = new(NPC_DEMOGORGON);
	npc->move(START_ROOM);
	npc->start_shutdown();

	write("Ok。\n");

	return 1;
}

int help (object me)
{
        write(@HELP
指令格式: reboot
 
重新起動遊戲, 系統會開始倒數計時, 十五分鐘後重新起動。
 
HELP
);
        return 1;
}
 
