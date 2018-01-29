// bandit.c

inherit NPC;

void create()
{
	set_name("土匪首領", ({ "bandit leader", "bandit", "leader" }) );
	set("gender", "男性");
	set("age", 31);
	set("long",
		"這個土匪看起來相當強悍，至少你從他的動作就可以看得出來他顯然\n"
		"是練過武功\的硬手，並不是泛泛之輩。\n");
	set("combat_exp", 14000);
	set("attitude", "aggressive");
	set_skill("axe", 70);
	set_skill("parry", 60);
	set_skill("dodge", 70);
	set_temp("apply/attack", 60);
	set_temp("apply/defense", 80);
	setup();
	carry_object(__DIR__"obj/hand_axe")->wield();
	carry_object(__DIR__"obj/hand_axe")->wield();
	add_money("silver", 10);
}
