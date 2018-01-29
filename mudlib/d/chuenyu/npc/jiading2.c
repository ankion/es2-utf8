// jiading.c

inherit NPC;
string kill_passenger(object who);
void create()
{
        set_name("藍衣家丁", ({ "guard" }) );
        set("gender", "男性" );
        set("age", 38);
        set("str", 28);
        set("cor", 27);
        set("cps", 25);
        set("int", 23);

        set("max_force", 100);
        set("force", 100);
        set("force_factor", 10);

        set("attitude", "heroism");

        set("long",@LONG
這是一位黑松堡的家丁，專負責盤察去黑松堡的行人。
LONG);

        set("combat_exp", 2000);
        set("score", 50);

        set_skill("hammer", 50);
        set_skill("dodge", 40);
        set_skill("parry", 50);
        setup();
        add_money( "coin" , 50);
        carry_object("/obj/cloth")->wear();
        carry_object(__DIR__"obj/7hammer")->wield();
}

void init()
{
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("checklooking");
                call_out("checklooking", 1, ob);
        }
}

void checklooking(object ob)
{

         if ( random((int)ob->query("per")) < 10  )
         {
        command("say 家丁喝道：站住！你幹什麼的。");
        command("say 看你那賊眉鼠眼，尖嘴猴腮的樣兒，決不是什麼好東西！");
                kill_passenger(ob);
         }
}

string kill_passenger(object who)
{
        set("attitude", "aggressive");
        kill_ob(who);
        return 0;
}

