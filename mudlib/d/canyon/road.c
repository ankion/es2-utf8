// ROOM:__DIR__"road"

inherit ROOM;
void create()
{
        set("short","碎石小路");
	set("long",@LONG
你正走在碎石小路上，荒涼的景色，不難想像，這□人煙稀少，很少
人會走到這□來，在路尾是一半圓形的土堆，其下有一鐵索，爬下鐵索(
chain)就可以通達黃石隘口，而東北方是銜接至雪亭鎮的青石官道。
LONG
	); // eof(long)

	set("item_desc", ([
        	"chain" : @TEXT
    一長條鐵索緣山壁而下，或許你可以試著攀爬(climb)。
TEXT
	]) );
	
	set("exits",([ /* sizeof()==1 */
		"northeast" : "/d/snow/sroad4",
	]) ); //eof(exits)
	
	setup();
	
} 

void init()
{
	add_action("do_climb", "climb");
}

int do_climb(string arg)
{ 
        object me;
        
        me=this_player();
        
	if ( arg != "chain" ) return 0;

        message_vision("$N手腳並用，努力地沿著鐵索向下攀爬而去。\n",me);
                       
	me->receive_damage("gin", 20);
	me->receive_damage("kee", 30);
	me->receive_damage("sen", 10);
	
	if ( ((int)me->query("gin") < 0) ||
	     ((int)me->query("kee") < 0) ||
	     ((int)me->query("sen") < 0) ) {   //判別式
           	tell_room(__DIR__"canyon1",me->name()+"體力不支了。\n");
            	me->move(__DIR__"canyon1");
	        return 1;
	}
        
        tell_room(__DIR__"canyon1",me->name()+"平安的從上面爬了下來。\n");
	me->move(__DIR__"canyon1");
        return 1;
}

