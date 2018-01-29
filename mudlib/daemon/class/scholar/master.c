// shiao.c

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("駱雲舟", ({ "master scholar", "master" }) );

        set("gender", "男性");
        set("age", 35);
        set("long",
		"駱雲舟生於京城有名的武林世家，他的本名是駱建炎，但是因爲生性喜愛\n"
		"四處遊蕩，遂自號「雲舟」，四處遊山玩水，結交豪傑異人。數年前繼承\n"
		"其父駱易而成爲步玄派的新任掌門，但是喜愛飄泊的個性仍然不改，令門\n"
		"中耆宿頭痛不已。\n" );

	set("attitude", "peaceful");
	create_family("步玄派", 7, "掌門人");

	set("str", 26);
	set("cor", 30);
	set("int", 28);
	set("cps", 30);

	set("force", 3000);
	set("max_force", 1600);
	set("force_factor", 20);

	set("combat_exp", 1000000);
	set("score", 200000);

	set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: exert_function, "recover" :),
                (: perform_action, "move.hasten" :),
        }) );
	
	set_skill("dodge", 100);
	set_skill("force", 80);
	set_skill("instruments", 70);
	set_skill("literate", 150);
	set_skill("move", 100);
	set_skill("music", 100);
	set_skill("parry", 90);
	set_skill("perception", 80);
	set_skill("sword", 100);
	set_skill("unarmed", 60);
	set_skill("mysterrier",120);
	set_skill("mystforce", 100);
	set_skill("mystsword", 100);
	map_skill("move", "mysterrier");
	map_skill("dodge", "mysterrier");
	map_skill("force", "mystforce");
	map_skill("sword", "mystsword");
	map_skill("parry", "mystsword");

	setup();
        carry_object(__DIR__"windspring")->wield();
        carry_object("/obj/cloth")->wear();
}

void attempt_apprentice(object ob)
{
         if (ob->query("marks/桃林"))  {
		 command("smile");
        	command("say 很好，" + RANK_D->query_respect(ob) +
"多加努力，他日必定有成。\n");
        	command("recruit " + ob->query("id") );
		ob->set("marks/書生", 0); 
		ob->set("marks/桃林", 0);	
		}
	    else {
		command ("say 你還是先走一趟東邊的桃林吧。\n");
		ob->set("marks/書生", 1);
		} 
}

void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "scholar");
}

