// fat_bandit.c

inherit NPC;

void create()
{
	set_name("土匪", ({ "bandit" }) );
	set("gender", "男性");
	set("age", 36);
	set("long",
		"這傢伙又矮又胖，圓滾滾的眼珠子在滿臉肥肉中骨碌碌地轉來轉去。\n");
	set("combat_exp", 500);
	set("score", 80);
	set("attitude", "aggressive");
	set("chat_chance", 10);
	set("chat_msg_combat", ({
		"\n矮胖子土匪大叫：把你身上的錢通通留下來！\n",
		"\n矮胖子土匪嘴裏不乾不淨地咒罵著。\n",
		(: this_object(), "call_for_help" :),
	}) );
	set_skill("sword", 20);
	set_skill("parry", 10);
	set_skill("dodge", 10);
	setup();
	carry_object(__DIR__"obj/short_sword")->wield();
	carry_object(__DIR__"obj/leather")->wear();
	add_money("silver", 5);
}

void call_for_help()
{
	object ob;

	if( query("called_help") || present("bandit chief", environment()) ) return;
	set("called_help", 1);
	command("say 他媽的，點子爪子太硬....");
	say("矮胖子土匪大叫：老大！老大！兄弟撐不住啦！");
	ob = new(__DIR__"bandit_chief");
	ob->move(environment());
	ob->start_help();
}
