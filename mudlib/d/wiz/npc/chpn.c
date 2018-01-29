// banker.c

#include <ansi.h>

inherit NPC;

string ask_me(object who);
void greeting(object ob);

void create()
{
	set_name("故事", ({ "chp" }) );
//	set("title", "板");
	set("gender", "男性" );
	set("age", 26);

	set("str", 22);
	set("cor", 30);
       set("cps", 30);
	set("int", 26);
	set("per", 23);
	set("con", 24);
	set("long", "故事是個看起來相當斯文的年輕人，不過有時候會有些心不在焉的\n"
                "樣子，頗有些隱者的風骨\n");
set("combat_exp", 200000);
	set("attitude", "friendly");
	set("pursuer", 1);
	set("env/wimpy", 70);

	set("max_atman", 1000);		set("atman", 1000);		set("atman_factor", 3);
	set("max_force", 1000);		set("force", 1000);		set("force_factor", 3);

        set("chat_chance_combat", 40);
	set("max_mana", 1000);		set("mana", 1000);		set("mana_factor", 3);

        set("chat_msg_combat", ({
                CYN "故事似笑非笑地望著你，臉上的神氣古理古怪，不知道在想些什
麼？\n" NOR,
                CYN "故事的身影晃了一下，似乎在你身上各處大穴摸了一下，不過也
許是你的錯覺。\n" NOR,
                CYN "故事神情忽然嚴肅了起來，不過好像是在想自己的英語翻譯事，與你無關
。\n" NOR,
                CYN "故事忽然呵呵呵地笑了起來，卻不知道在笑些什麼....\n" NOR,
                (: perform_action, "sword.counterattack" :),
                (: cast_spell, "drainerbolt" :),
                (: cast_spell, "feeblebolt" :),
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :),
        }) );
                
	set_skill("unarmed", 100);
	set_skill("parry", 100);
	set_skill("dodge", 100);
	set_skill("force", 100);
	set_skill("celestrike", 100);
	set_skill("celestial", 100);
	set_skill("fonxansword", 100);
	set_skill("six-chaos-sword", 100);
	set_skill("chaos-steps", 100);
	set_skill("spells", 100);
	set_skill("necromancy", 100);

	map_skill("force", "celestial");
	map_skill("unarmed", "celestrike");
	map_skill("dodge", "chaos-steps");
	map_skill("sword", "fonxansword");
	map_skill("spells", "necromancy");
	map_skill("sword", "fonxansword");
	
	setup();
	
	carry_object("/obj/longsword")->wield();
	carry_object("/obj/cloth")->wear();

	//add_money("gold", 10);
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(3) ) {
                case 0:
                        say( "故事笑咪咪地說道：這位" + RANK_D->query_respect(ob)
                                + "，進來歇息一下吧。\n");
                        break;
                case 1:
                        say( "故事用毛巾抹了抹頭上的汗，說道：這位" + RANK_D->query_respect(ob)
                                + "，幫我翻譯幾頁英文資料吧。\n");
                        break;
                case 2:
                        say( "故事說道：這位" + RANK_D->query_respect(ob)
                                + "，有什麼意見可以提呀。\n");
                        break;
        }
}

int accept_fight(object me)
{
	command("say 咦... 要打就真打吧，光是較量多沒意思？");
	command("grin");
	kill_ob(me);
	return 1;
}
