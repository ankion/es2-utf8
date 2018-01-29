// bandit_guard.c

inherit NPC;

void create()
{
	set_name("土匪嘍羅", ({ "bandit" }) );
	set("gender", "男性");
	set("age", 33);
	set("long",
		"這傢伙滿臉橫肉，一付凶神惡煞的模樣，令人望而生畏。\n");
	set("combat_exp", 3600);
//	set("pursuer", 1);
	set("score", 260);
	set("bellicosity", 600);
	set("attitude", "aggressive");
	set_skill("sword", 50);
	set_skill("parry", 40);
	set_skill("dodge", 40);
	setup();
	carry_object(__DIR__"obj/short_sword")->wield();
	add_money("silver", 5);
}
