inherit NPC;

void create()
{
     set_name("老道士", ({"old taoist", "taoist"}) );
     set("gender", "男性");
     set("age", 46);
     set("class", "taoist");
     set("long", "一位四處雲遊的老道士, 他正在觀心觀掛單中。\n"
                 "看他飽經滄桑的臉孔, 似乎他也是經歷過無數的大風大浪。\n");
     set("attitude", "peaceful");
     set("combat_exp", 2500);

     set_skill("dodge", 10);
     set_skill("parry", 15);
     set_skill("whip", 25);

     setup();

     carry_object(__DIR__"obj/whip")->wield();
     carry_object(__DIR__"obj/old_robe")->wear();
     add_money("silver", 5);
}

int accept_fight(object ob)
{
     command("say 無量壽佛 ! 貧道年邁力衰, 怎是施主的對手。\n");
     return 0;
}
