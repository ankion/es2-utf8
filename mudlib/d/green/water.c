#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
	set("short","溪水邊");
	set("long",@LONG
你來到了一條小溪的旁邊，溪水很清澈，緩緩地向南流去，西面
灌木叢中隱隱的有條小路。
忽然水(water)中有一道亮光閃過，不過看不清是什麼，你是否要下去
找一找(search)?
LONG
);
	set("exits",([
	"west" :__DIR__"outdoor",
	"north":__DIR__"stoneroom",
	]) );
	create_door("north","密門","south",DOOR_CLOSED);
	setup();
}

void init()
{
	add_action("do_search","search");
}

int do_search(string arg)
{
	object me,obj;
	
	me = this_player();
	if ( !arg || arg != "water" )
		return notify_fail("你要在那兒找?\n");

        message_vision("$N跳入溪水之中，開始仔細尋找....\n",me);		

	if ( me->query("八卦陣") ) {
	   if ( random(2) ) {
		obj = new("/d/green/obj/windsword");
		obj->move(me);
		message_vision("$N竟從水中找出一把"+HIW"追風劍"NOR+"!\n", me);
		return 1 ;
	   }
	   me->delete("八卦陣");
	}
        message_vision("$N在水中忙了半天，結果一無所獲。\n",me);		
	return 1 ;
}

