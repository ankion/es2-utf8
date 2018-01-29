// bfighter.c

inherit NPC;

void create()
{
        set_name("趟子手", ({ "bfighter" }) );
        set("gender", "男性" );
        set("age", 38);
        set("str", 28);
        set("cor", 27);
        set("cps", 25);
        set("int", 23);

        set("max_force", 100);
        set("force", 100);
        set("force_factor", 3);

        set("pursuer", 1);
        set("env/wimpy", 30);

        set("long",@LONG
這是一位鏢局的趟子手，負責鏢局的護鏢任務。
LONG);

        create_family("振遠鏢局", 2, "趟子手");

        set("combat_exp", 10000);
        set("score", 200);

        set("chat_chance", 20);
        set("chat_msg", ({
                "趟子手喊道：振遠鏢局..., 盛名遠揚...\n",
                (:random_move :)
        }) );

        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
                "趟子手喊道：教你嚐嚐我的厲害！\n",
                "趟子手叫道：我們鏢局可不是好惹的！\n"
                "趟子手大叫：我一定要殺了你，替鏢局揚名！\n"
        }) );

        set_skill("unarmed", 60);
        set_skill("parry", 50);
        set_skill("dodge", 30);
        set_skill("blade", 50);
        set_skill("force", 20);
        set_skill("literate", 10);

        set_skill("spring-blade", 40);

        map_skill("blade", "spring-blade");

        setup();
        carry_object("/obj/weapon/blade")->wield();
}
