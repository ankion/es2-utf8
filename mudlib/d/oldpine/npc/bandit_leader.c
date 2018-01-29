// bandit_leader.c

inherit NPC;

void create()
{
	set_name("土匪首領", ({ "bandit leader", "chief", "leader" }) );
	set("gender", "男性");
	set("age", 47);
	set("long",	"這傢伙眼神兇惡，一雙精光四射的眼珠正盯著你的脖子。\n");
	set("combat_exp", 50000);
	set("score", 7700);
	set("bellicosity", 3000);
	set("attitude", "aggressive");

	set("max_force", 700);
	set("force", 1300);
	set("force_factor", 4);

	set("chat_chance_combat", 20);
	set("chat_msg_combat", ({
		"\n土匪首領陰惻惻地說道：這種三腳貓的功\夫也敢上老鬆寨來撒野？！\n",
		"\n土匪首領說道：去你的，老子今天要剁下你的頭來練練毒爪！\n",
		"\n土匪首領虎吼一聲，欺身上前。\n"
	}) );
	set_skill("blade", 60);
	set_skill("parry", 70);
	set_skill("dodge", 70);

	// Because the chief's 武功 is not done yet, set apply to replace it.
	set_temp("apply/attack", 70);
	set_temp("apply/dodge", 50);

	setup();
	carry_object(__DIR__"obj/blade")->wield();
	carry_object(__DIR__"obj/leather")->wear();
	add_money("silver", 30);
}

