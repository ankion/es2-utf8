// Room: /d/canyon/bamboo/bamboo3.c

inherit ROOM;

void create()
{
	set("short", "竹林道");
	set("long", @LONG
北方有一個大黃石堵住去路，洋洋灑灑的藍光從大黃石的四周漫
漫而出，竹林參天，在此成一半凹型，團團圍住了北方的去路，若想
一窺究竟，看來非得推開這巨大的黃石才行，風勢愈來愈強，四周的
竹子發出了嗡嗡的鳴聲，彷佛叫人不要靠近，此地之主人看似不歡迎
別人來參觀。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"south" : __DIR__"bamboo2",
]));

	setup();
}

void init ()
{
	add_action("do_move","move");
	add_action("do_enter","enter");
	add_action("go_enter","go");
}
int do_move(string arg)
{
	object me;
	
	if ( arg!="stone" ) return 0;
	
	me=this_player();
	
	if ( ((int)me->query("force") < 560) ||
	     ((int)me->query("max_force") < 560) ||
	     ((int)me->query("force_factor") < 40 ) ) { 
		tell_object(me, "你出力不太夠喔！\n");
		return 1;
	}

	me->receive_damage("gin",20);
	me->receive_damage("kee",60);
	me->receive_damage("sen",20);
	
	if( query("exits/enter") ) return 1;
	
	set("exits/enter",__DIR__"train");
        message_vision("$N將大黃石緩緩的向左邊移動，而出現了一個小小的隙縫。\n"
        		,me);
	return 1;
}

int do_enter()
{
	if( !query("exits/enter") ) return 0;
	
	message_vision("當$N通過隙縫，大黃石又急速地合閉。\n",this_player());
	delete("exits/enter");
	this_player()->move(__DIR__"train");
	return 1;
}

int go_enter(string arg)
{
	if( !query("exits/enter") ) return 0;
	        
	if( arg!="enter" ) return 0;
	
	message_vision("當$N通過隙縫，大黃石又急速地合閉。\n",this_player());
	delete("exits/enter");
	this_player()->move(__DIR__"train");
	return 1;
}
