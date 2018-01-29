// earth-warp.c

#include <ansi.h>
#include <command.h>
#include <login.h>

inherit F_CLEAN_UP;

int scribe(object me, object sheet, string arg)
{
        if( me->is_fighting() ) return notify_fail("你正在戰鬥中！\n");
        
        if( (int)me->query("mana") < 90 ) return 
notify_fail("你的法力不夠了！\n");
        if( (int)me->query("sen") < 10 ) return 
notify_fail("你的精神不夠集中！\n");

        sheet->set_name(YEL "陰界傳送符" NOR, ({ "earth-warp sheet", 
"sheet"}) );    
        sheet->set("attach_func", (: call_other, __FILE__, "do_warp", arg :) 
);
        me->add("mana", -90);
        me->receive_damage("sen", 10);

        return 1;
}

int do_warp(string target, object who)
{
        object env;

        if( who && who!=this_player() )
                return notify_fail("陰界傳送符只能對自己使用。\n");

        env = environment(this_player());
        message("vision",
                HIB + this_player()->name() + "祭起一張陰界傳送符。\n\n"
                
"忽然四周吹起了一陣涼颼颼的陰風，陰風之中彷佛有許多人影在晃動...\n\n"
                "然後一陣火光突然爆起！\n" NOR, env);
        DROP_CMD->main(this_player(), "all");
        this_player()->move(DEATH_ROOM);
        message("vision",
                CYN "可是...." + this_player()->name() + "已經不見了。\n" 
NOR, env);
        message("vision",
                CYN 
"你只覺得身子不斷下墜，一直下墜，一直下墜，一直下墜，一直下墜 .....\n\n"
                NOR     
"不知道什麼時候，你發現你其實一直都站在堅硬的地面上，可是四周的景物\n\n"
                        "卻不一樣了....\n", this_player() );
        
        return 1;
}
 
