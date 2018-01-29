// judge.c

inherit NPC;

void create()
{
        set_name("寶官", ({ "judge" }) );
        set("gender", "男性" );
        set("age", 22);
        set("long", "他臉上的表情彷彿是看到了你口袋裏的錢一般。\n");
        set("per", 25);
        set("combat_exp", 500);
        set("attitude", "friendly");
        set_skill("unarmed", 50);
        set_skill("parry", 70);

        set("inquiry", ([
                "賭" : "客官您把錢給我就行了。\n",
        ]) );

        setup();
        add_money("silver", 1);
        carry_object("/obj/cloth")->wear();
        carry_object("/obj/example/dagger")->wield();
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
        if( !ob || environment(ob) != environment() ) return;
        switch( random(4) ) {
                case 0:
                        say( "快來賭，快來賭啦！\n");
                        break;
                case 1:
                        say( "贏了可是利滾利啊！\n");
                        break;
        }
}

void pay_player(object who, int amount)
{
        object ob;

        if( amount < 1 ) amount = 1;
        if( amount/100 ) {
                ob = new(SILVER_OB);
                ob->set_amount(amount/100);
                ob->move(who);
                amount %= 100;
        }
        if( amount ) {
                ob = new(COIN_OB);
                ob->set_amount(amount);
                ob->move(who);
        }
}

int accept_object(object who, object ob)
{
        int val;

        val = ob->value();
        if( !val ){
                return notify_fail("物品不能折價，您還是先去折現吧！\n");
                return 0;
        }
        else{
                say("什麼？ 您押小？！好的。\n"); 
                if( random(10) < 8 ) {
                        say( "寶官說道：開！押大的贏啦！這位"
                                + RANK_D->query_respect(who)
                                + "，您下次一定好運！\n");
                }
                else{
                        say( "寶官說道：開！押小的贏啦！這位"
                                + RANK_D->query_respect(who)
                                + "真是好運道！這是您的贏頭。\n");
                        pay_player(this_player(), val * 2);
                }
        return 1;
        }
}

