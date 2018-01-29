//thief.c
inherit NPC;

void create()
{
        set_name("飛賊", ({ "thief" }) );
        set("rank", "盜賊");
        set("gender", "男性" );
        set("age", 35);
        set("int", 25);
        set("con", 28);
        set("long", @LONG
    飛賊經常出沒於大戶人家, 因爲他輕功高強, 官府也拿他沒有辦法。
LONG
);
        set("combat_exp", 3000);
        set("attitude", "heroism");
        set("env/wimpy", 70);

        set("chat_chance", 40);
        set("chat_msg", ({
                "飛賊說道: 小心我把你變成窮光蛋! 嚇得你不禁把錢攥緊了\n",
               (: random_move :)
        }) );

        set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
                "飛賊惡狠狠的說道: 快滾！這沒你的事！",
                "飛賊喝道: 你要是敢惹我, 咱們以後可沒完!"
        }) );

        set_skill("dodge", 140);
        set_skill("parry", 100);
        set_skill("unarmed", 30);
        set_skill("move", 100);
        set_skill("stealing", 70);

        setup();

        add_money("gold", 3);
        carry_object("/u/cloud/obj/cloth/black_cloth")->wear();
        set("score",-30);
}

init()
{
        //int steal_flag;
        object ob;

        ::init();

        if( interactive(ob = this_player()) && !is_fighting() ) {
                if (random((int)ob->query("kar")) < 2) {   // 偷的概率
                        remove_call_out("steal_it");
                        call_out("steal_it", 1, ob);
                }
        } else {        // 處於戰鬥狀態則必偷
                remove_call_out("steal_it");
                call_out("steal_it", 1, ob);
        }

}

void steal_it(object ob)
{
        if( !ob || environment(ob) != environment() ) return;

        command("grin");
        command("steal silver from " + ob->query("id"));

}

int accept_fight(object me)
{
        command("say 好小子, 居然管起大爺的事來, 看招!");
        command("grin");
        kill_ob(me);
        return 1;
}

