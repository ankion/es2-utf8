// boater.c

inherit NPC;

string	cross_river();

void create()
{
        set_name("船伕", ({ "boater" }) );
        set("title", "渡口");
        set("gender", "男性" );
        set("age", 30);
        set("long", "船伕的皮膚曬得黝黑，臉上的滄桑是多年擺渡的痕跡。\n");
	set("str", 27);
        set("combat_exp", 1500);
        set("attitude", "heroism");
        set_skill("unarmed", 100);
        set_skill("parry", 50);
        set_skill("dodge", 30);

        set("inquiry", ([
		"過江" : (: cross_river :),
		"擺渡" : (: cross_river :), 
        ]) );

	setup();
	add_money("coin", 200);
        carry_object("/obj/cloth")->wear();
}

int accept_object(object who, object ob)
{
        if( !who->query("marks/船伕") ) {
                if( ob->value() >= 2 ) {
			command("nod");
			message("vision", "船伕說：客官可以過江啦！\n",
                                 who );
	                message("vision", "船伕拉過條小船，你走了上去。\n",
                        	 who );
                        who->set("marks/船伕", 1);
                        return 1;
                } else {
                        say("這麼少？我還要養家呀！\n");
                        return 0;
                }
        } else{
                say("多謝這位"+RANK_D->query_respect(ob)+"！\n");
		who->set("marks/船伕", 0);
	}
        return 1;
}

string	cross_river()
{
	return "交五兩銀子";
}

