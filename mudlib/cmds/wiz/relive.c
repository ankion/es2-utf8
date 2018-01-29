inherit F_CLEAN_UP;

#include <dbase.h>
#include <net/dns.h>

mapping skills;

int main(object me, string arg)
{
        string *sk;
        int i;
	object player;

	if ( !arg )
		return notify_fail ("你要誰活一次？\n");
 
	if (!objectp(player = new ("/obj/login")))
		return notify_fail ("不能new一個object。\n");

	player->set("id", arg);
	if (!player->restore() )
		return notify_fail ("沒有這個人啊！\n");

       if( wizardp(player) || !player->mapp(skills) ) 
		return notify_fail ("這人沒必要復活。\n");

        sk = keys(skills);
	for(i = 0; i<sizeof(sk); i++) {
			skills[sk[i]]++;
                	}

        return 1;
}

