// hell_guard.c

#include <ansi.h>

inherit NPC;

void create()
{
	string *order = ({"子", "醜", "寅", "卯", "辰", "巳", "午", "未", "申", "酉", "戌", "亥"});

	set_name( (order[random(12)]) + "陰鬼卒", ({ "hell guard", "guard" }) );
	set("long", "這是一位來自陰界的守護神，專門擔任護法之責。\n");
	set("attitude", "friendly");

	set("max_gin", 1000);
	set("max_kee", 1000);
	set("max_sen", 1000);

	set("max_atman", 100);
	set("atman", 100);
	set("max_mana", 100);
	set("mana", 100);

	set("str", 40);
	set("cor", 30);
	set("cps", 25);

	set("combat_exp", 100000);

	set("chat_chance", 15);
	set("chat_msg_combat", ({
		name() + "喝道：孽障！隨我赴陰司受審吧。\n"
	}) );

	set_skill("fork", 90);
	set_skill("parry", 70);
	set_skill("dodge", 50);

	setup();

	carry_object(__DIR__"obj/steel_armor")->wear();
	carry_object(__DIR__"obj/steel_fork")->wield();
}

int heal_up()
{
	if( environment() && !is_fighting() ) {
		call_out("leave", 1);
		return 1;
	}
	return ::heal_up() + 1;
}

void leave()
{
	message("vision",
		HIB + name() + "說道：末將奉法主召喚，現在已經完成護法任務，就此告辭！\n\n"
		+ name() + "的身形發出幽暗的藍光，沈入地下不見了。\n" NOR, environment(),
		this_object() );
	destruct(this_object());
}

void invocation(object who)
{
	int i;
	object *enemy;

	set("possessed", who);
	message("vision",
		HIB "一道藍光從地底升起，藍光中出現一個手執鋼叉、面目猙獰的鬼卒。\n\n"
		+ name() + "說道：末將奉法主召喚，特來護法！\n" NOR,
		environment(), this_object() );
	enemy = who->query_enemy();
	i = sizeof(enemy);
	while(i--) {
		if( enemy[i] && living(enemy[i]) ) {
			kill_ob(enemy[i]);
			if( userp(enemy[i]) ) enemy[i]->fight_ob(this_object());
			else enemy[i]->kill_ob(this_object());
		}
	}
	set_leader(who);
}
