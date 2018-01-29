// bandit.c

inherit NPC;

void create()
{
	set_name("土匪探哨", ({ "bandit" }) );
	set("gender", "男性");
	set("age", 19);
	set("long",
                "這人滿臉匪氣，一付百無聊賴的模樣，令人望而生厭。\n");
//		"這傢伙滿臉橫肉，一付凶神惡煞的模樣，令人望而生畏。\n");
	set("combat_exp", 600);
	set("score", 60);
	set("attitude", "aggressive");
	set_skill("sword", 10);
	set_skill("parry", 10);
	set_skill("dodge", 10);
	setup();
	carry_object(__DIR__"obj/short_sword")->wield();
	add_money("silver", 3);
}
