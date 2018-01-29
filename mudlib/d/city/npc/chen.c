// master chen

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("陳天星", ({ "master chen", "master" }) );
	set("title", "振遠鏢局總鏢頭");
        set("nickname", "刀拳雙絕");
        set("rank_info/respect", "陳總鏢頭");
        set("gender", "男性" );
        set("age", 63);

        set("long",@LONG
陳天星從十五歲出道至今已經有近五十個年頭了。二十五歲時自己
創建了振遠鏢局，苦心經營三十八載，使之而今成爲京師第一大鏢
局.而他憑着春風快意刀法和天邪神掌被江湖同道稱爲「刀掌雙絕」
。綺雲鎮的陳劍秋是其侄子，如今也赫赫有名。
LONG);

        set("attitude", "peaceful");
        set("combat_exp", 1000000);
        set("score", 200000);

        set("str", 38);
        set("cor", 27);
        set("cps", 29);
        set("int", 30);

        set("max_force", 3200);
        set("force", 2000);
        set("force_factor", 40);

	set("inquiry", ([
		"name": "呵呵…你連我都不知道嘛？去打聽打聽吧。\n",
		"振遠鏢局": "這可是我一手創建的啊！可惜我也老了。\n",
		"陳劍秋": "他是我侄子，有什麼事找他？\n",
		"天邪神掌": "那是我和於蘭天武交換武功學的\n",
		"拜師": "是劍秋推薦的嘛？可有他的信物？\n"
		]));

        create_family("振遠鏢局", 0, "總鏢頭");
        assign_apprentice("弟子", 0);

        set_skill("force", 100);
        set_skill("unarmed", 100);
        set_skill("blade", 150);
        set_skill("parry", 100);
        set_skill("dodge", 80);

        set_skill("celestial", 80);
	set_skill("celestrike", 80);
	set_skill("spring-blade", 150);
	set_skill("pyrobat-steps", 70);

        map_skill("force", "celestial");
	map_skill("unarmed", "celestrike");
	map_skill("blade", "spring-blade");
	map_skill("parry", "spring-blade");
	map_skill("dodge", "pyrobat-steps");

        setup();

	carry_object(__DIR__"obj/duoqing_blade")->wield();
}

int accept_object(object who, object ob)
{
	if ((string)ob->query("id") != "letter") {
		command("angry");
		tell_object(who, "不要戲弄我！\n");
		return 1;
		}

	if ((string)ob->query("master_id") != (string)who->query("id")) {
		message_vision("陳天星狐疑地望着$N，說
這是你的嘛？\n", who);
		return 1;
		}

        command("smile");
        command("say 果然是劍秋侄兒推薦來的。我收你啦。\n");
        command("recruit " + who->query("id") );
	
	return 1;
}

void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) ) {
		ob->set("title", "振遠鏢局第一代弟子");
                ob->set("class", "guardman");
		}
}

