// entrance.c

#include <login.h>
#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "巫師會客室");
	set("long",
		"這裏是巫師和玩家聊天的地方，如果你有什麼意見要讓巫師們知道，在這裏\n"
	"留言是最快的途徑，不過如果是對於遊戲中的問題，請您先確定我們提供的說明\n"
	"文件裏沒有說明，再提出疑問，巫師的主要職責並不是教玩家如何玩。\n");
	set("exits", ([
		"west" : "/d/wiz/hall1",
		"southeast": "/d/snow/inn" ]) );
	set("no_fight", 1);
	set("no_magic", 1);
        set("objects", ([
                "/d/wiz/npc/chpn" : 1 ]) );
	create_door("southeast", "木門", "northwest", DOOR_CLOSED);

	setup();
	call_other( "/obj/board/query_b", "???" );
}

int valid_leave(object me, string dir)
{
	if( dir=="west" && !wizardp(me) )
		return notify_fail("那裏只有巫師才能進去。\n");
	return ::valid_leave(me, dir);
}

void init()
{
        add_action("re_route_cmd","",1);
}

int re_route_cmd(string str)
{
        string cmd;
        int i;
        string *invalid_cmds;
        cmd = query_verb();
        invalid_cmds = ({"meditate", "practice", "study", "exercise", "learn", 
                         "respirate"
                       });
        i = member_array(cmd, invalid_cmds);
        if (i == -1) return 0;
        else write("這裏是巫師會客室, 不是讓你拿來練功的地方哦!\n");
        return 1;
}

