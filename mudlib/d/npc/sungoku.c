// sangoku.c

#include <ansi.h>

inherit NPC;
inherit F_SAVE;

void create()
{
	set_name( "孫悟空", ({ "sun goku", "sun", "goku" }) );
	if( !restore() ) {
		set("short", "來自「七龍珠」的" HIC "孫悟空" NOR "(Sun goku)");
		set("long",
			"孫悟空是來自鳥山明的漫畫「七龍珠」，你別小看他現在一付傻頭傻腦的樣子\n"
			"，他可是 ESII 第一個自我成長型的 NPC，從他被創造出來以後，他所獲得的\n"
			"戰鬥經驗都會儲存下來。\n" );
		set("gender", "男性" );
		set("race", "賽亞人");
		set("chat_chance", 15);
		set("chat_msg", ({
			(: this_object(), "random_move" :),
			CYN "孫悟空說道：哈羅！來比武吧？\n" NOR,
			CYN "孫悟空翻了個跟斗，用一隻手指撐在地下，說道：這招你會不會啊？\n" NOR,
		}) );
		set("chat_msg_coombat", ({
			CYN "\n孫悟空扮個鬼臉，說道：來呀！再來呀！\n" NOR,
			CYN "\n孫悟空說道：這一招是爺爺教我的，厲害吧！\n" NOR,
		}) );

		// We have 7 pills per reset.
		set("pills", 7);

		// This is the initial apply for his race.		
		set("perm_apply", ([
			"attack":	10,
			"dodge":	10,
			"damage":	5,
		]) );

		set("age", 9);
		set("str", 44);
		set("cor", 24);
		set("cps", 18);
		set("per", 24);
		set("int", 42);

		set_skill("unarmed", 1);
		set_skill("dodge", 1);
		set_skill("force", 1);
		set_skill("parry", 1);
	}

	set_temp("apply", query("perm_apply"));
	setup();
	carry_object(__DIR__"obj/kame_suit")->wear();
}

string query_save_file()
{
	return __DIR__"data/sungoku";
}

void reset()
{
	int learn;

	// Restore the pills.
	set("pills", 7);

	// Improve sungoku's natural ability if there's potential available.
	if( (int)query("potential") > (int)query("learned_points") ) {
		learn = (int)query("potential") - (int)query("learned_points");
		add_temp("apply/attack", learn / 3);
		add_temp("apply/dodge", learn / 3);
		add_temp("apply/damage", learn / 3);
		add("learned_points", (learn / 3) * 3);
	}

	save();
}

int accept_fight(object who)
{
	if( is_fighting() ) {
		if( random(query("eff_kee")) > (int)query("kee") ) {
			say( CYN "孫悟空大叫：這麼多人我打一個？不行不行，等我打敗這些人再跟你打！\n" NOR);
			return 0;
		} else {
			say( CYN "孫悟空大叫：這麼多人我打一個？沒關係，我一定讓你們好看！\n" NOR);
			return 1;
		}
	}
	say( CYN "孫悟空很高興地說道：好啊，好啊，我要出招了...\n" NOR);
	return 1;
}

int receive_damage(string type, int pts)
{
	int damage;

	damage = ::receive_damage(type, pts);
	if( (type=="kee") && (damage > (int)query("max_kee") / 5) ) {
		say( CYN "孫悟空捂著受傷的地方，說道：好痛啊...真有你的....\n" NOR);
		if( random(query("kee")) < damage)
			random_move();
	}

	if( (int)query("pills")
	&&	(((int)query("kee")) < 20 
		|| ((int)query("gin") < 20) 
		|| ((int)query("sen") < 20) )) {
		say( HIY "孫悟空從口袋摸出一粒花梨塔貓仙人給他的仙豆吞了下去。\n" NOR);
		set("gin", query("eff_gin"));
		set("kee", query("eff_kee"));
		set("sen", query("eff_sen"));
		add("pills", -1);
	}
	return damage;
}

varargs void improve_skill(string skill, int amount, int raw)
{
	// Thus we can gain skill levels from direct fighting.
	::improve_skill(skill, amount);
}

void revive()
{
	// This is a feature of sungoku's race. See the comic :P.
	add("combat_exp", (int)query("combat_exp") / 3 + 10);
	reset();
	::revive();
}

void kill_ob(object ob)
{
	fight_ob(ob);
}

void defeated_enemy(object ob)
{
	say(CYN "孫悟空作出一個 V 字型的手勢，說道：我贏了！" NOR);
	remove_killer(ob);
}
