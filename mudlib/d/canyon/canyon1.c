// ROOM:__DIR__"canyon1"

inherit ROOM;
void create()
{
        set("short","黃石隘口尾");
	set("long",@LONG
腳下爲碎石黃土路，兩側是高聳入雲的荒山，向上仰望乃似無邊無際
穹空，北緣爲一山壁，壁上有一長達十七、八丈的鐵索(chain) ，上面大
概就是人家所謂的「關外綠洲－雪亭鎮」。
LONG
	); // eof(long)

	set("item_desc", ([
        	"chain" : @TEXT
    一長條鐵索緣山壁而上，若無絕佳的體力就好不要輕意攀爬(climb)。
TEXT
	]) );
	
	set("exits",([ /* sizeof()==1 */
		"southwest" : __DIR__"canyon2",
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

        message_vision("$N手腳並用，努力地沿著鐵索向上攀緣上去了\n",me);
                       
	me->receive_damage("gin", 30);
	me->receive_damage("kee", 40);
	me->receive_damage("sen", 20);
	
	if ( ((int)me->query("gin") < 0) ||
	     ((int)me->query("kee") < 0) ||
	     ((int)me->query("sen") < 0) ) {   //判別式
           	tell_room(__DIR__"road",me->name()+"體力不支了。\n");
            	me->move(__DIR__"road");
	        return 1;
	}
        
        tell_room(__DIR__"road",me->name()+"平安的從下面爬了上來。\n");
	me->move(__DIR__"road");
        return 1;
}

