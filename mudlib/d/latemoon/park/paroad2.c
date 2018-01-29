inherit ROOM;
#include <ansi.h>

string look_sign(object me);

void create()
{
   set("short", "□香榭");
	set("long", @LONG
轉過翠嫣橋，隱隱露出一帶黃泥築就矮牆，牆頭用稻莖掩護，
有幾百株杏花，如噴火蒸霞一般，裏面數楹茅屋，外面卻是桑、
榆、槿、杉各色樹木新條，隨其曲折編就兩溜青籬，籬外有一土  
井，旁有一石牌(sign)。旁邊有一些佳蔬菜花。
LONG
	);
    set("item_desc", ([
        "sign": (: look_sign :)
    ]) );
	set("exits", ([ /* sizeof() == 2 */
       "east" :__DIR__"bridge2",
       "northwest" :__DIR__"moon3",

]));

    set("objects", ([
        __DIR__"npc/rabbit" : 2 ]) );
	setup();
}

string look_sign(object me)
{
    if( wizardp(me) )
        return "這是一個任務提示。暫時未開放。\n";
    else
        return "\n 「六神」、「四鬼」、「三靈」 \n\n" +
            HIM "         旋芒震日月\n" +
                "         寶劍護河山\n\n" NOR ;
}
