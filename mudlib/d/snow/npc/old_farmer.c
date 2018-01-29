// old_farmer.c

inherit NPC;

void create()
{
	set_name("老農夫", ({ "old farmer", "farmer" }) );
	set("gender", "男性" );
	set("age", 63);
	set("long", "你看到一位面色黝黑的農夫。\n");
	set("combat_exp", 20);
	set("attitude", "friendly");
	set("env/wimpy", 60);
	set("chat_chance_combat", 50 );
	set("chat_msg_combat", ({
		"農夫叫道：殺人哪！殺人哪！\n",
		"農夫叫道：有土匪哪！光天化日下打劫哪！\n",
		(: command, "surrender" :),
	}) );
	setup();
	carry_object(__DIR__"obj/raincoat")->wear();
	carry_object(__DIR__"obj/sandals")->wear();
	add_money("coin", 20);
	replace_program(NPC);
}
