// tao_2.cup_taoist.c

inherit NPC;

void create()
{
        set_name("殭屍護法", ({ "taoist tfighter", "tfighter" }) );
        set("gender", "男性");
        set("age", 32);
        set("long",
"殭屍護法是茅山派的護法，着一身黑色的道袍\n"
);
        set("combat_exp", 50000);
        set("score", 20);

        set("class", "taoist");

        set("int", 30);
        set("cps", 30);
        set("spi", 30);
        set("pursuer", 1);

        set("force", 150);
       set("max_force", 150);
        set("force_factor", 5);

        set("atman", 150);
        set("max_atman", 150);

        set("mana", 300);
        set("max_mana", 300);
        set("mana_factor", 5);

        set("inquiry", ([
                "谷衣心法":
"谷衣心法是我茅山派爲對抗邪魔外道所創的內功心法。\n",
                "茅山派":
"我茅山派自張天師開山立派至今，世世代代皆以降妖伏魔爲己任。\n"
        ]) );
        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
                (: cast_spell, "drainerbolt" :),
                (: cast_spell, "netherbolt" :),
                (: cast_spell, "feeblebolt" :),
                (: cast_spell, "invocation" :),
        }) );

        create_family("茅山派", 6, "弟子");

        set_skill("literate", 50);
        set_skill("magic", 30);
        set_skill("force", 30);
        set_skill("spells", 60);
        set_skill("unarmed", 50);
        set_skill("sword", 100);
        set_skill("parry", 100);
        set_skill("dodge", 100);
        set_skill("gouyee", 60);

        map_skill("force", "gouyee");

        set_skill("taoism", 70);
        set_skill("necromancy", 60);

        map_skill("spells", "necromancy");

        set_temp("apply/dodge", 30);
        set_temp("apply/armor", 30);

        setup();

        add_money("gold", 3);
        carry_object("/obj/weapon/longsword")->wield();

}

int accept_fight(object me)
{
        if( (string)me->query("family/family_name")=="茅山派" ) {
                command("nod");
                command("say 進招吧。");
                return 1;
        }
        command("say 茅山派不和別派的人過招。");
        return 0;
}
