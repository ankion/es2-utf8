// general.c

#include <ansi.h>

inherit NPC;

//#define PATH "/u/t/tnn/canyon/camp2"
#define PATH "/d/canyon/camp2"

void create()
{
	set_name("嚴廷殷", ({ "master general","master","general" }) );
	set("title", "天邪派第十六代弟子");
	set("nickname", YEL "鎮國大將軍" NOR);
	set("gender", "男性");
	set("age", 45);
	set("long",
        	"容光煥發，左佩刀，右佩劍，威風□□，其高七尺六寸，虎背\n"
        	"熊腰，年輕時同和大天邪於蘭天武同拜一師，武功\造詣不在大\n"
        	"天邪之下，但志向不同，後成了京師武功\第一、人人稱羨的鎮\n"
        	"國大將軍。\n");

	set("attitude", "peaceful");

	set("str", 29);
	set("int", 28);

	set("inquiry",([
		"黃石隘口" : "你眼睛脫窗啊，這□就是黃石隘口。\n",
		"後備兵" : "我不管這種事的，你別來煩我。\n",
		"兵器庫" : "你找死啊！問這種問題，你想幹麻啊。\n",
		"印鑑" : "你怎麼知道的？幫我找找吧，找到了我送你禮物。\n",
	]) );
	set("force", 1800);
	set("max_force", 1800);
	set("force_factor", 20);
	set("max_gin", 200);
	set("eff_gin", 200);
	set("gin", 200);
	set("max_sen", 200);
	set("eff_sen", 200);
	set("sen", 200);
	
	set("combat_exp", 900000);

        set("chat_chance_combat", 80);
	set("chat_msg_combat", ({
		(: exert_function, "powerup" :),
		(: exert_function, "recover" :)
	}) );
	
	set_skill("sword", 80);
	set_skill("six-chaos-sword", 85);
	set_skill("force", 80);
	set_skill("celestial", 80);
	set_skill("parry", 50);
	set_skill("dodge", 60);
	set_skill("pyrobat-steps", 60);
	set_skill("unarmed", 80);
	set_skill("celestrike", 85);
	
	map_skill("sword", "six-chaos-sword");
	map_skill("parry", "six-chaos-sword");
	map_skill("force", "celestial");
	map_skill("unarmed", "celestrike");
	map_skill("dodge", "pyrobat-steps");
	
	
	setup();

	carry_object( __DIR__"obj/broken_sword")->wield();
//carry_object( __DIR__"obj/broken_sword")->wield();
	carry_object( __DIR__"obj/cloud_armor")->wear();

}

int accept_object(object who,object ob)
{
	object obj;

	if ( (string)ob->name() == "[1;33m印鑑[0m") {
		command("say 真是謝謝你了。");
		command("smile");
		command("say 爲了答謝你，這把古劍送你，當做報酬吧。");
//		obj=new(__DIR__"obj/old_sword");
                obj=new("/d/canyon/npc/obj/old_sword");
		obj->move(who);
//		call_out( (: destruct :), 1, ob);
 		return 1;
 	}
 	
	if ( (string)ob->name() == "印鑑" ) {
		command("say 你拿給我的是什麼東西啊!");
 		command("say 別想拿這種東西來騙我");
		command("say 給我滾出去");
 		who->set_temp("將軍/kick", 1);
		who->move(PATH);
		return 0;
	}
	
	if ( !ob->value() ) {
		command("say ㄟ....Ｔhank Ｙou!!!");
		command("grin");
//		call_out( (: destruct :), 1, ob);
		return 1;
	}
	
	command("say 啊，真是謝謝你了。");
	return 1;
}
