
#include <ansi.h>
inherit ROOM;

void create()
{
     set("short","傍廳");
	set("long", @LONG
這裏是晚月莊接待賓客的傍廳，廳中擺了一張桌几，上面擺著
一塊大紅鑲金桌巾，靠東壁面西設著半舊青緞靠背引枕，兩張太師
椅座。桌几上有一精緻的茶壺，旁有盛好的上等茗茶。
LONG
	);
    set("resource/water", 1);
	set("exits", ([ /* sizeof() == 2 */
    "south" :__DIR__"latemoon1",
]));

    set("objects", ([
         __DIR__"npc/yumay" : 1  ]) );
	setup();
}
int valid_leave(object me, string dir)
{
        string item;
        object obj;

        item = "tea cup";
        if( !objectp(obj = present(item, me)) )  {
                tell_object(me, "你起身往南離開!\n" NOR );
        }  else  {
        if ( me->query_temp("latemoon/茶") ) {
                tell_object(me, HIC "你將瓷杯交回給雨梅。\n" NOR);
                me->set_temp("latemoon/茶", 0);
        destruct(obj);
           }
        }
        return 1;
}
