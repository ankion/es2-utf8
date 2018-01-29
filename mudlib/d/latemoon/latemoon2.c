#include <room.h>

inherit ROOM;

void create()
{
	set("short","內廳");
	set("long", @LONG
走入內廳，你看到襲地鋪滿紅毯。四面相對十二張雕漆椅上，都
是一色灰鼠椅□小褥，廳中擺了小屏風，四周掛滿山水墨畫。一個木
隔架，旁邊還有一碧紗櫥(closet)。
LONG
	);
	set("item_desc", ([
		"closet" : @TEXT
這是一個上等木材作成的小櫥子，裏面放了一些物品。
你看到一件件的美麗衣飾，真想取出(take cloth)看看。
TEXT
	]) );

	set("exits", ([ /* sizeof() == 2 */
		"west" :__DIR__"latemoon4",
	]));

    set("objects",([
        __DIR__"npc/zauron" :  1 ]) );
	create_door("west","儀門","east", DOOR_CLOSED);
	setup();
}

void init()
{
	add_action("do_take", "take");
	add_action("do_search","search");
}

void reset()
{
	::reset();
	set("take_available" , 2);
	set("make_cockroach", 5);
}

int do_take(string arg)
{
	object obj;

	if( !arg ) return notify_fail("你要拿什麼 ? \n");
	if( arg !="cloth" ) { 
		if ( query("make_cockroach") ) {
			message_vision("$N一聲尖叫 ! 突然出現一隻大蟑螂。\n",this_player());
			obj = new(__DIR__"npc/cockroach");
			obj->move(environment(this_player()));
			add("make_cockroach", -1);
		}
		return 1;
	}
	if( query("take_available") ) {
		obj = new(__DIR__"obj/skirt");
		obj->move(this_player());
		message_vision("$N從櫥子內取出$n。\n",this_player(),obj);
		add("take_available", -1);
		return 1;
	}
	write("櫥子內的衣服好像被拿光了。\n");
	return 1;
}

int do_search(string arg)
{
	object obj,who;

	who = this_player();
	if ( !arg )	return notify_fail("你要找什麼?\n");
	if ( arg !="bracelet" )	{
		 write("你盲目的找著，但無發現什麼!\n");
	  return 1;
	}
	else  {
	if( !who->query_temp("moon/問題二") ) {
	 write("你盲目的找著，但無發現什麼!\n");
		return 1;
	}
	 if ( who->query_temp("latemoon/手鐲") ) {
		 write("你翻箱倒櫃想找出手鐲，但似乎毫無所獲。\n");
		 return 1;
	 }
     obj = new("/d/latemoon/obj/bracelet");
	 obj->move(who);
	 message_vision("$N從櫥子內取出$n。\n",this_player(),obj);
	 who->set_temp("latemoon/手鐲", 1);
	return 1;
	}
}
