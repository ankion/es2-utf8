// Room: /d/wiz/courthouse.c

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "法院");
	set("long", @LONG
這裏是東方故事的巫師審問機器人的法院，你一定是被人檢舉或是
行爲太像機器人，纔會來到這裏，如果你答不出審判官的三個問題，會
被做上記號，超過三次的人將會被處以極刑，好好回答吧。
LONG
	);
	set("no_fight", 1);
	set("no_magic", 1);
	set("no_spells", 1);
	set("objects", ([
		__DIR__"npc/judge":1 ]) );

	setup();
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
	invalid_cmds = ({"enforce", "meditate", "practice", "study", "drop",
                         "exercise", "learn", "scribe", "conjure", "enchant",
                         "exert", "perform", "respirate"
                       });
        i = member_array(cmd, invalid_cmds);
        if (i == -1) return 0;
        else write("到了法院你還練啥功啊, 搞不清楚狀況哦。\n");
        return 1;
}

void test_me(object me)
{
	me->set_temp("old_startroom", me->query("startroom"));
	me->set("startroom", __FILE__);
	me->set_temp("last_location", base_name(environment(me)));
	message_vision("忽然一陣閃光罩住了$N。\n", me);
	me->move(this_object());
}
