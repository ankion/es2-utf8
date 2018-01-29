// b_header.c

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("陳劍秋", ({ "master guardman", "guardman", "master" }) );
        set("nickname", "霹靂刀");
        set("gender", "男性" );
        set("age", 38);
        set("str", 28);
        set("cor", 27);
        set("cps", 25);
        set("int", 23);

        set("max_force", 1000);
        set("force", 1000);
        set("force_factor", 3);

        set("rank_info/respect", "陳鏢頭");

        set("long",@LONG
    陳劍秋在十幾年前創立了振遠鏢局，憑着一手春風快意刀法在遠近
頗有些名頭，因此鏢局的生意還算可以。
LONG);

        create_family("振遠鏢局", 1, "鏢頭");

        set("combat_exp", 1000000);
        set("score", 20000);

//        set("chat_chance_combat", 60);
//        set("chat_msg_combat", ({
//                (: perform_action, "sword.counterattack" :)
//        }) );

        set_skill("unarmed", 60);
        set_skill("parry", 100);
        set_skill("dodge", 60);
        set_skill("blade", 100);
        set_skill("force", 20);
        set_skill("literate", 40);

        set_skill("spring-blade", 120);

        map_skill("blade", "spring-blade");

        set("inquiry", ([
                "淳風武館" : 
"淳風武館是先父所創，在下辱承其名，雖忝掌封山門戶，不敢忘了先人遺志。",
                "name": "在下姓陳，人稱霹靂刀",
                "霹靂刀": "江湖上的弟兄看得起在下就這麼叫開了，實在是慚愧。",
		"陳天星": "他是我師叔，如果你幫我找到忘憂草並交給我，我就介紹你去那學藝。",
		"忘憂草": "我在喬陰縣城遊玩時丟的，據說被藏在一個隱蔽的地方了。",
			]) );

        setup();
        carry_object("/u/cloud/obj/npc/b_header/moon_blade")->wield();
}

void attempt_apprentice(object ob)
{
        if( ((int)ob->query_cor() < 25) ) {
// ("cor") < 25) ){ 
                command("say 走鏢危險甚大，依我看" + 
RANK_D->query_respect(ob) + "似乎不宜冒這份險？");
                return;
        }
        command("smile");
        command("say 很好，" + RANK_D->query_respect(ob) + 
"多加努力，本鏢局不會虧待你的。\n");
        command("recruit " + ob->query("id") );
}

void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "guardman");
}

int accept_object(object who, object obj)
{
	object letter;

	if ((string) obj->query("name") != "忘憂草") {
		command ("angry");
		command ("say 你拿什麼東西唬我？\n");
		return 1;
		}

	if ((string) who->query("family/family_name") != "振遠鏢局") {
		command ("heng");
		command ("say 你是何人？爲什麼有我的忘憂草？\n");
		return 1;
		}

	if ((string) obj->query("master_id") != (string) who->query("id") ) {
		message_vision ("$N笑了笑說：“這不是你得到的吧？”。\n", this_object());
		return 1;
		}

	message_vision ("$N大喜過望，：“好，好，我這就給你寫信。”\n", this_object());
	message_vision ("$N提筆刷刷點點，頃刻間一封信寫就。\n", this_object());
	message_vision ("陳劍秋交給$N一封信件。\n", who);
	letter = new  (__DIR__"obj/letter");
	letter->set("master_id", (string)who->query("id"));
	letter->move (who);
	message_vision ("$N說到路上小心，把信直接給陳師叔。\n", this_object());
	return 1;
}
 
