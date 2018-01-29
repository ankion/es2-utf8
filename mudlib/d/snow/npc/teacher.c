// teacher.c

inherit NPC;

void follow_player();

void create()
{
	set_name("魏無極", ({ "teacher", "wey" }) );
	set("title", "教書先生");
	set("gender", "男性" );
	set("age", 47);
	set("int", 26);
	set("long",
		"魏無極是個博學多聞的教書先生，他年輕時曾經中過舉人，但是\n"
		"因爲生性喜愛自由而不願做官，魏無極以教書爲業，如果你付他\n"
		"一筆學費，就可以成爲他的弟子學習讀書識字。\n");
	set("inquiry", ([
		"學費": ({
			"嗯 ... 讀書識字是做人的第一步。",
			"學好了讀書識字的本領，勝過於百萬的家財。",
			"所以說學問是金錢買不到的。",
			0,
			0,
			0,
			"雖然學問是無價的，不過如果你有心的話 ...",
			"只要五兩銀子。",
			}),
		"讀書識字": "對，讀書識字。",
		"劉安祿": ({
			"哦 ... 你是說野羊山寨的二寨主，人稱血手劉三的劉安祿嗎？",
			"他又出來做惡了？",
			"你帶我去見他，讓我跟他說幾句話。",
			(: follow_player :),
			})
	]) );
	set("attitude", "peaceful");
	set_skill("literate", 60);
	setup();
}

/*
void follow_player()
{
	object ob;

	if( !objectp(ob = query_temp("last_asker")) ) return;
	set_leader(ob);
}

*/
int recognize_apprentice(object ob)
{
	if( !ob->query("marks/魏無極") ){
		say("魏無極說道：咦？我不記得收過你這個學生啊....\n");
		return 0;
	}

	return 1;
}

int accept_object(object who, object ob)
{
	if( !who->query("marks/魏無極") ) {
		if( ob->value() >= 500 ) {
			say("魏無極點了點頭，說道：很好，從今天起你隨時可以來問我有關讀書識字(literate)的任何問題。\n");
			who->set("marks/魏無極", 1);
			return 1;
		} else {
			say("魏無極說道：你的誠意不夠，這錢還是拿回去吧。\n");
			return 0;
		}
	} else
		say("魏無極點了點頭，說道：哦，向你這麼有心的學生還真是不多見，好好努力將來必定前途無量，謝了。\n");
	return 1;
}

int accept_learn(object me, string skill)
{
	return 1;
}
