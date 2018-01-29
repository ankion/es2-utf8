inherit NPC;

void create()
{
        set_name("商人", ({ "trader"}) );
        set("gender", "男性" );
        set("age", 42);
        set("long", "這是一位從關外來的商人。\n");
        set("combat_exp", 5000);
        set("attitude", "friendly");
        set("env/wimpy", 30);
        set_skill("blade", 30);
        set_skill("shortsong-blade", 10);
        set_skill("fall-steps", 30);
        set_skill("dodge", 100);
        set_skill("parry", 20);
        map_skill("blade", "shortsong-blade");
        map_skill("parry", "shortsong-blade");
        map_skill("dodge", "fall-steps");
        set("chat_chance", 20);
        set("chat_msg", ({
                "什麼世道，幾個臭錢就可以買官作。\n",
		"這年頭，生意不好做啊！\n",
		(: random_move :),
        }) );
        setup();
        add_money("silver", 50);
        carry_object("/obj/cloth")->wear();
        carry_object(__DIR__"obj/hu-blade")->wield();
}
