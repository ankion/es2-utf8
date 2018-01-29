// worker.c

inherit NPC;

void create()
{
	set_name("苦力", ({ "worker" }) );
	set("gender", "男性" );
	set("long", "一個苦力打扮的漢子在這裏等人來僱用(employment)。\n");
	set("attitude", "friendly");
	set("inquiry", ([
		"employment": "小人的工資一天只要一百文錢，大人只管吩咐。",
		"name": "小人的名字難聽得緊，不敢勞大人過問。",
		"home": "小人是喬陰縣雪亭鎮人氏。",
	]) );
	set("age", 27);
	set("str", 27);
	set("env/wimpy", 100);
	setup();
	carry_object("/obj/cloth")->wear();
}

int accept_order(object me, string verb)
{
	if( (string)me->query("id") == (string)query("boss_id") ) {
		switch(verb) {
			case "kill":
				command("say 小人家有老母妻小，這個 .... 這個 ....");
				return 0;
			case "fight":
				command("say 小人不會武功\，" + RANK_D->query_respect(me)
					+ "您說笑了。\n");
				return 0;
			default:
				return 1;
		}
	}
	return 0;
}

int accept_info(object me, string command)
{
	return (string)me->query("id") == (string)query("boss_id");
}

int accept_object(object me, object obj)
{
	if( query("boss_id") ) {
		command("say 對不起，小的已經有人僱了。");
		return 0;
	}

	if( (int)obj->value() < 100 ) {
		command("say 一百文錢一天，一個子兒也不能少。");
		return 0;
	}
	set("boss_id", me->query("id"));
	call_out("end_duty", (obj->value()/100) * 1440 );
	command("say 謝謝" + RANK_D->query_respect(me) +"！有什麼事只管吩咐！\n");
	command("follow " + me->query("id"));
	return 1;
}

void end_duty()
{
	command("tell " + query("boss_id") + " 小的下工時間到了。");
	command("bow");
	delete("boss_id");
}
