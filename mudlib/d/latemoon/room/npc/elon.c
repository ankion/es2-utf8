inherit NPC;
inherit F_MASTER ; 

void create()
{
        set_name("璦倫",  ({ "eelon"  }) );
        set("gender", "女性" );
         set("age", 37);
        set("long", @TEXT
TEXT
);
        set("attitude", "peaceful");
        set("class", "dancer");
	set("title","晚月莊開山祖師");
        set("combat_exp", 3000000);
        set("score", 1000);

	set("str",21);
	set("int",28);
	
        set_skill("unarmed",150);
        set_skill("dodge", 150);
	set_skill("sword",120);
	set_skill("force",150);
	set_skill("parry",120);
	set_skill("whip",150);
	set_skill("iceforce",130);
	set_skill("throwing",150);	
        set_skill("stormdance", 130);
        set_skill("tenderzhi", 130);
	set_skill("snowwhip",130);
        map_skill("dodge","stormdance");
        map_skill("unarmed","tenderzhi");
	map_skill("force","iceforce");
	map_skill("whip","snowwhip");
        set("force", 4000);
        set("max_force", 3000);
        set("force_factor", 5);
	
	set("inquiry", ([
                "拜師":
		"哦....想拜老身爲師，好...\n不過得先接受測試(accept test)，接下我三鞭。"
        ]) );

        create_family("晚月莊", 0, "弟子");

        setup();
        carry_object("/d/latemoon/obj/deer_boot")->wear();
        carry_object("/d/latemoon/obj/blue_dress")->wear();
	carry_object("/obj/weapon/whip")->wield();
}

void init()
{
	::init();
	add_action("do_accept","accept");
}

int do_accept(string arg)
{
        mapping guild;

        if( arg== "test" ) {
		if ( this_player()->query("gender") != "女性" ) {
			command("say 老身不收男徒!\n");
			return(1);
		}
		if ( this_player()->query("combat_exp") < 100000 )
			return 1 ;			
		say("\n璦倫說道：小心了，這是第一鞭...\n\n");

                COMBAT_D->do_attack(this_object(), this_player(),
query_temp("weapon"));
                if( (int)this_player()->query("kee") < 0
                || !present(this_player(), environment())) {

			command("sigh");
			command("shake");
                        return 1;
                }
		say("\n璦倫面露微笑：好！第二鞭來了...\n\n");

                COMBAT_D->do_attack(this_object(), this_player(),
query_temp("weapon"));
                if( (int)this_player()->query("kee") < 0
                || !present(this_player(), environment())) {

			say("\n璦倫嘆了口氣道：看來還是不行啊...\n\n");
                        return 1;
                }
		say("\n璦倫鼓勵道：很不錯，看這最後一鞭...\n\n");

                COMBAT_D->do_attack(this_object(), this_player(),
query_temp("weapon"));
                if( (int)this_player()->query("kee") < 0
                || !present(this_player(), environment())) {
			say("\n璦倫嘆了口氣道：太可惜了！\n\n");
			command("shake");
                        return 1;
                }
		say("\n璦倫露出慈祥的面容：看來我沒看錯人。\n\n");

                command("recruit " + this_player()->query("id") );
		this_player()->set("title","晚月莊第一代弟子");
                return 1;
        }
        return 0;
}

void attempt_apprentice(object me)
{
	if ( me->query("combat_exp") < 100000 ) {
     command("say 拜師! 不敢當，我都老了!你去找「芷萍」好了，看她收不收你? ");
	}
	else
	if ( me->query("gender") != "女性" )
	command("say 老身不收男徒!\n");
	else
        if((string)me->query("title")!="普通百姓")
         {
            command("chat "+me->query("title")+me->query("nickname")+
            me->query("name")+"要叛師！！！");
            command("angry");
            kill_ob(me);
            return;
         }

	else {
        say(RANK_D->query_respect(me) + "若真的有心，不妨讓我看看你的所學\n");

        tell_object(me, "如果想拜師的話，就請接受測試（accept test）\n");
}
}
