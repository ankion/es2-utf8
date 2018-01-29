// Room: /d/oldpine/keep2.c

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "老鬆寨");
	set("long", @LONG
這裏應該是老鬆寨了，雖然圍繞著你的牆都是木頭搭成的，但是仔
細一看，在許多險要的位置都放了不少沙包石堆，後面顯然是埋伏人手
的好地方，如果有人貿然從大門口攻進來，肯定會吃大虧的，大寨的門
在你的西邊，東邊越過一排木樁之後就是大廳。
LONG
	);
	
	set("exits", ([ /* sizeof() == 2 */
		"west" : __DIR__"keep1",
		"east" : __DIR__"keep3",
	]));
	set("objects", ([
		__DIR__"npc/bandit_guard" : 2,
		__DIR__"npc/bandit_leader" : 1
	]) );

	setup();
}

int valid_leave(object me, string exit)
{
	int i;
	object ob;

	if( exit != "east"
	||	!query("exits/west") )
		return 1;

	message("vision",
		HIY "你聽到你身後有幾個聲音大叫：把門關上！把門關上！一個也不許\讓他們溜走！\n" NOR
			"接著「轟」地一聲，通往外面的大門已經被一塊大石堵死了。\n",
		this_object() );
	delete("exits/west");
	if( ob = find_object(__DIR__"keep1") )
		ob->delete("exits/east");

	i = 5;
	while(i--) {
		ob = new(__DIR__"npc/bandit_guard");
		ob->move(this_object());
		ob->kill_ob(me);
	}
	return 1;
}

void reset()
{
	object ob;

	::reset();
	set("exits/west", __DIR__"keep1" );
	if( ob = find_object(__DIR__"keep1") )
		ob->set("exits/east", __FILE__);
	
}

void pipe_notify()
{
	object ob;

	message("vision",
		"你聽到一陣軋軋的輪盤絞動聲，堵住門口的大石慢慢地被移開了。\n",
		this_object() );
	set("exits/west", __DIR__"keep1" );
	if( ob = find_object(__DIR__"keep1") )
		ob->set("exits/east", __FILE__);
}
