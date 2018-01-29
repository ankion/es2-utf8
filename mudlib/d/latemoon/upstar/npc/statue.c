inherit NPC;
#include <ansi.h>
 
void create()
{
        set_name("人靈「區冥」",  ({ "statue" }) );
        set("title", "神像");
        set("gender", "女性" );
        set("age", 27);
        set("long", @TEXT
人靈「區冥」乃勇士寒於的魂魄所化成的十三個精靈之一。
晚月莊的開山先輩，傳說是其後裔子孫。故其爲
晚月莊的祖先神位。
TEXT
);
        set("combat_exp", 50000000);
        set_skill("unarmed", 100);
        set_skill("dodge", 100);
        set_skill("tenderzhi", 100);
        set_skill("iceforce", 100);
        set_skill("stormdance", 100);
        set_skill("force",100);
        map_skill("force","iceforce");
        map_skill("dodge","stormdance");
        map_skill("unarmed","tenderzhi");
        set("force", 7000);
        set("max_force", 7000);
        set("force_factor", 30);
        set("attitude", "friendly");
         set_temp("apply/armor", 100);
        
        setup();
}
void init()
{
       object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}
void greeting(object ob)
{
        if( !ob || !present(ob, environment(this_object())) ) return;
     if ((string)ob->query("class") != "dancer" ) {
          say( HIY "你有一種奇特的感覺，彷佛有人在盯著你看。\n" NOR);
          ob->receive_damage("sen", 20);
          return;
    }
    return;
}

