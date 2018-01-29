// bandit_chief.c

inherit NPC;

void create()
{
	set_name("土匪老大", ({ "bandit chief", "chief" }) );
	set("gender", "男性");
	set("age", 39);
	set("long",
		"這傢伙眼神兇惡，一雙精光四射的眼珠正盯著你的脖子。\n");
	set("combat_exp", 6000);
	set("score", 700);
	set("attitude", "aggressive");
	set("chat_chance", 10);
	set("chat_msg_combat", ({
		"\n土匪老大陰惻惻地說道：乖乖地躺下吧！\n",
		"\n土匪老大說道：自從劉老三洗手不幹以後，只怕這附近還沒有我的對手！\n",
		"\n土匪老大虎吼一聲，欺身上前。\n"
	}) );
	set_skill("blade", 60);
	set_skill("parry", 50);
	set_skill("dodge", 50);

	// Because the chief's 武功 is not done yet, set apply to replace it.
	set_temp("apply/attack", 50);
	set_temp("apply/dodge", 30);

	setup();
	carry_object(__DIR__"obj/blade")->wield();
	carry_object(__DIR__"obj/leather")->wear();
	add_money("silver", 30);
}

void start_help()
{
	say("一條人影從樹林間躍出，身手矯健，顯是武功\不弱。\n");
	command("say 哈哈哈... 連這幾個小角色也打發不了，站開一點！\n");
}
