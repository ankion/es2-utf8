// chuenyu.c

inherit NPC;

string kill_passenger(object who);

void create()
{
        set_name("劉老農", ({ "liu" }) );
        set("gender", "男性" );
        set("age", 57);
        set("str", 27);
        set("int", 12);
        set("per", 10);
        set("long", @LONG
劉老農今年快六十了。但手腳還算靈活。
LONG
);
        set("attitude", "peaceful");

        set("combat_exp", 10000);
        set("bellicosity", 0);
        set("marks/老劉本人", 1);

        set_skill("sword", 150);
        set_skill("unarmed", 100);
        set_skill("dodge", 120);
        set_skill("parry", 120);
        set_skill("liuh-ken", 70);
        set_skill("six-chaos-sword", 150);
        set_skill("pyrobat-steps", 80);
                        
        map_skill("dodge", "pyrobat-steps");
        map_skill("sword","six-chaos-sword");
        map_skill("unarmed","liuh-ken");
        setup();

        add_money("coin", 50); 
        carry_object("/obj/cloth")->wear();
        carry_object(__DIR__"obj/parrybook");

}
int accept_fight(object me)
{
        command("say 老頭子哪裏是您的對手？");
        return 0;
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting",2 , ob);
        }
}
void greeting(object ob)
{
        object book;
        object sword;
        if((int) ob->query("marks/murder") == 0)
        {
        if( (int) ob->query("marks/老劉") == 0 ) 
        say( "劉老農說道：“這位"+ RANK_D->query_respect(ob) 
+"，可否見到小女娟兒？” \n");
        else
        {

        set_skill("six-chaos-sword",150);
        set_skill("pyrobat-steps", 80);
        map_skill("unarmed","liuh-ken");
        say( "劉老農說道：“這位"+ RANK_D->query_respect(ob) 
+"，多謝答救小女娟兒。” \n");
        say( "劉老農說道：“這口劍，這本密笈贈於"+ RANK_D->query_respect(ob) 
+"。” \n");
        say( "劉老農說道：“這處非久留之地，我等去也。” \n");
        say( "劉老農領着娟兒匆匆離去。” \n");

         ob->set("marks/老劉", 0);
        sword = new(__DIR__"obj/hengbing");
        book = new(__DIR__"obj/parrybook");
        sword->move(ob);
        book->move(ob); 
        destruct(this_object());
        }
        }
        else
                call_out("killhim",1,ob);
}

killhim(object ob)
{
        ob->set("marks/murder", 0);
        ob->set("marks/老劉", 0);
        set("title", "悲憤欲絕");
        
say("劉老農悲憤欲絕的罵道：你．．你．．你們居然殺了我女兒，納命來！\n");  

                set("chat_msg_combat", ({
"劉老農悲憤欲絕的罵道：你．．你．．你們居然殺了我女兒，納命來！",
                (: random_move :),
        }) );
        set("chat_chance", 15);
        set("chat_msg", ({
"劉老農悲憤欲絕的罵道：你．．你．．你們居然殺了我女兒，納命來！",
                (: random_move :),
        }) );
        set_temp("apply/force",4000);
        set_temp("apply/max_force", 2200);
        set_temp("apply/force_factor", 30);
        set_temp("apply/combat_exp", 1000000);
        set_temp("apply/damage", 250);
        carry_object(__DIR__"obj/hengbing")->wield();
        kill_ob(ob);
        ob->kill_ob(this_object());

}
 
