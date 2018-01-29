#include <room.h>

#include <ansi.h>
inherit ROOM;

void create()
{
    set("short",HIY "密室" NOR);
	set("long", @LONG
這是一間密室。地上鋪著可以合地打坐的大理石牀。四周掛了一
些兵器，正面牆上寫了偌大的 『 舞 』字！ 地板上隱約看到一幅先
天八卦圖。中央畫著兩儀，八個角落分別是：乾坤兌離震巽坎艮、等
卦相。牆上畫著幾幅玄天玉女翩然起舞的美妙步法。
LONG
	);

    set("exits", ([
        "north" :__DIR__"miroom2",
    ]) );
    set("objects", ([
       __DIR__"obj/hankie" : 1,
     ]) );
	create_door("north","垂花門","south",DOOR_CLOSED);

	setup();
}
void init()
{
         add_action("do_dancing", "dancing");
         add_action("do_get", "get");
}

int do_dancing(string arg)
{
   object me;

   me = this_player();

   if( (string)me->query("gender") == "男性" ) {
   if ( (int)me->query("sen") < 100 )
        return notify_fail("你現在的神太少了，無法專注跳出舞步！\n");
        me->receive_damage("sen",80);
   }
   if( (string)me->query("gender") == "女性" ) {
   if ( (int)me->query("sen") < 50 )
        return notify_fail("你現在的神太少了，無法專注跳出舞步！\n");
        me->receive_damage("sen", 50);
   }
     if ( arg!="out" )
     return notify_fail("你在卦象中跳起舞來。但似乎不得要領！\n" );
     if( arg == "out" )
       message_vision("$N在卦象中跳起舞來..一曲"+HIG"「 西出陽關 」"+
          NOR"突然...\n",
                        this_player() );
         this_player()->move(__DIR__"bamboo");

         return 1;
}
int do_get(string arg)
{
     object me;
     
     me = this_player();

	if (arg !="dance-book")
	return 0;
	else me->receive_damage("sen",50);
	return 0;
}
