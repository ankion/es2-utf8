#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
   set("short", "小花池");
	set("long", @LONG
這是一個小花池，清澈的池水含著淡淡的幽香。池周圍有許多奇花    
異草，時如至芝蘭之室，清香襲腦，溫馨蕩魄。繽紛的花瓣飄在池上，
雲幢羽葆中，簇擁著許多師姐妹，有的嘻戲玩耍，有的翩然起舞。你也
想到小花池中沐浴休憩(take bath)。
LONG
	);
    set("resource/water", 1);
    set("objects", ([
      __DIR__"npc/fireangel" : 1,
       __DIR__"npc/eton" : 1,
    ]) );

	set("exits", ([ /* sizeof() == 2 */
     "west" :__DIR__"bathroom1",

]));

	setup();
}
void init()
{
          add_action("do_takebath","take");
}
int do_takebath(string arg)
{
       object me;
       me = this_player();

       if( !arg || (arg!= "bath") )
            return notify_fail("你想作什麼? \n");
       if( (string)me->query("gender") != "女性" ) {
            me->apply_condition("rose_poison", 15);
            tell_object(me, HIG "你覺得池水好像有種奇特的沁涼！\n" NOR );
       } else {
       message_vision("$N在池子中盡情沐浴，舒服的泡在池中。\n",this_player() );

       me->receive_damage("gin", 10);
       me->receive_heal("sen", random(5)+5);
       }
       return 1;
}
