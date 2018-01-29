// proposer.c

inherit NPC;

string ask_for_employment();

void create()
{
	set_name("媒婆", ({ "proposer" }) );
	set("gender", "女性" );
	set("long",
		"一個打扮得花枝招展的中年婦人，如果你對哪家姑娘有意思，可以請她\n"
		"幫你去提親。\n");
	set("attitude", "friendly");
	set("inquiry", ([
		"employment" : (: ask_for_employment :),
		"提親" : (: ask_for_employment :),
	]) );
	set("rank_info/respect", "大娘");
	set("age", 38);
	set("env/wimpy", 100);
	setup();
	carry_object(__DIR__"obj/color_cloth")->wear();
}

string ask_for_employment()
{
	object me;

	if( query_temp("proposing") ) return 0;

	me = this_player();
	if( !me->query("can_speak") )
		return "哎喲 ... 別跟我開玩笑 ... 去找個牽豬哥的吧，呵呵呵 ...\n";
	if( (string)me->query("class")=="bonze" )
		return "啊？這位" + RANK_D->query_respect(me) + "您得先還俗吧？呵呵呵 ...\n";
	if( me->query("gender") != "男性" )
		return "這位" + RANK_D->query_respect(me) + "別心急，有點耐心慢慢等，呵呵呵 ...\n";
	command("giggle");
	if( me->query("spouce") ) 
		return "這位" + RANK_D->query_respect(me) + "您的胃口還真不小啊，呵呵呵 ...\n";
	if( query_temp("custom") )
		return me==query_temp("custom") ?
			  "是～是～ 咱們還等什麼，帶我去見那位姑娘吧！\n"
			: "等一會兒，待我說定這位大爺的親事，下一個就輪到您 ...\n";
	command("say 好好好，我幫您去說(propose)準成，別忘了準備一個大紅包喲 ...");
	set_leader(me);
	command("say 咱們走吧！");
	set_temp("custom", me);
}

int accept_order(object me, string verb)
{
	if( me==query_temp("custom") && verb=="propose" ) {
//		command("grin");
//		command("say 您真是貴人多忘事，這個 ... 這個 ... 準備好了嗎？");
		return 1;
	}
	return 0;
}

int perform_propose(object ob)
{
	if( !ob || environment(ob)!=environment() ) {
		command("say 咦？那位姑娘人呢？");
		set_leader(query_temp("custom"));
		delete_temp("proposing");
		return 0;
	}

	switch(query_temp("proposing")) {
		case 1:
			command("whisper " + ob->query("id") + query_temp("custom")->name()
				+ "仰慕您已經很久了，特地託我來替他說親 ...");
			add_temp("proposing", 1);
			return 1;
		case 2:
			command("whisper " + ob->query("id") + "哪 ... 就是您面前這一位，人品不錯吧！");
			add_temp("proposing", 1);
			return 1;
		case 3:
			command("nod " + query_temp("custom")->query("id") );
			command("whisper " + ob->query("id") + "如果您中意，就跟我點點頭(nod)吧，不然搖搖頭(shake)我再去物色別的對象 ...");
			add_temp("proposing", 1);
			return 1;
		default:
			if( (int)query_temp("proposing") > 100 ) {
				command("sigh");
				command("say 看來這位姑娘根本不理我 ...");
				delete_temp("proposing");
				return 0;
			}
			switch(random(30)) {
				case 0:
					command("say " + query_temp("custom")->name()
					+ "仰慕您已經很久了，不知姑娘考慮得怎樣？");
					break;
				case 1:
					command("say " + query_temp("custom")->name()
					+ "這樣的人品真是不錯了，姑娘您認爲呢？");
					break;
				case 2:
					command("whisper " + ob->query("id") 
					+ "如果您中意，就點點頭(nod)吧，不然搖搖頭(shake)我再去物色別的對象 ...");
					break;
				case 3:		command("smile"); break;
				case 4:		command("giggle"); break;
				case 5:		command("hmm"); break;
			}
			add_temp("proposing", 1);
			return 1;
	}
}

int force_me(string cmd)
{
	object me, ob;
	string target;

	if( sscanf(cmd, "propose %s", target) ) {
		me = this_player(1);
		ob = present(target, environment());
		if( !ob || !userp(ob) || !ob->query("can_speak")
		||	(string)ob->query("gender") != "女性") {
			command("?");
			command("say 誰？您中意的姑娘是哪一位？");
			return 0;
		}
		if( ob->query("spouce") ) {
			command("whisper " + me->query("id") + "人家可是有夫之婦喲，您還是考慮考慮吧！");
			return 0;
		}
		command("smile");
		command("whisper " + me->query("id") + " 您放心，看我的！");
		command("smile " + ob->query("id"));
		set_temp("proposing", 1);
		set_leader(ob);
		start_busy( (: perform_propose, ob :) );
		return 1;
	}
	else return ::force_me(cmd);
}

int accept_object(object me, object obj)
{
}

void end_duty()
{
}
