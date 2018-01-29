#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
    set("short","密室");
	set("long", @LONG
這是一間密室。地上鋪著可以合地打坐的大理石牀。四周掛了一
些兵器，正面牆上寫了偌大的 『 舞 』字！ 地板上隱約看到一幅先
天八卦圖。中央畫著兩儀，八個角落分別是：乾坤兌離震巽坎艮、等
卦相。牆上畫著幾幅玄天玉女翩然起舞的美妙步法。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
    "north" :__DIR__"latemoon7",
]));

    create_door("north","石門","south", DOOR_CLOSED);
	setup();
}

void init()
{
         add_action("do_dancing", "dancing");
	 add_action("do_search" , "search");
}

int do_dancing(string arg)
{
     object me;
      me = this_player();

      if( (string)me->query("gender") == "男性" ) {
      if ( (int)me->query("sen") < 100 )
           return notify_fail("你現在的神太少了，無法專注跳出舞步！\n");
           me->receive_damage("sen", 50);
      }
      if( (string)me->query("gender") == "女性" ) {
      if ( (int)me->query("sen") < 50 )
           return notify_fail("你現在的神太少了，無法專注跳出舞步！\n");
           me->receive_damage("sen", 30);
      }

        if( !arg || (arg!= "out" && arg!="yu-fong") )
             return notify_fail("你在卦象中跳起舞來。但似乎不得要領！\n");

       if ( arg=="yu-fong" ) {
                
message_vision("$N在卦象中跳起舞來..一曲"+HIM"「 有鳳來儀 」"+NOR"突然...\n",
                        this_player() );
         this_player()->receive_damage("sen", 50);
         this_player()->move(__DIR__"miroom");
        } else  if ( arg=="out" ) {
          message_vision("$N在卦象中跳起舞來..一曲"+HIM"「 西出陽關 」"+
          NOR"突然...\n",
                        this_player() );
         this_player()->move(__DIR__"bamboo");
        }

         return 1;
}

int do_search(string arg)
{
	object obj;
	if ( !arg || arg != "bed" ) {
		write("你要找什麼？\n");
		return 1 ;
	}
	if ( !this_player()->query("mark/dance-book") ) {
	message_vision("$N在石牀附近找了很久，結果一無所獲。\n",this_player());
	return 1 ;
	}	
	message_vision("$N在石牀後面找到了一本舞曲譜！\n",this_player());
	obj = new(__DIR__"obj/book");
	obj->move(this_player());
	this_player()->delete("mark/dance-book");
	return 1 ;
}
		
