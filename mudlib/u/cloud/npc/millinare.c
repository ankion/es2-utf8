// millinare , added by kindman

#include <ansi.h>

inherit NPC;	

void create()
{
        set_name("張百萬", ({ "zhang" }) );
        set("title", "主人");
        set("gender", "男性" );
        set("age", 43);	
        set("long",
             "一位精明能幹的大奸商\n");
        set("combat_exp", 10000);
        set("attitude", "friendly");

        set_skill("literate", 70);
        set_skill("dodge", 300);
        set_skill("unarmed", 200);
        setup();

        add_money("gold", 5);
}	
