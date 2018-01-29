// mercenary.c

inherit NPC;
inherit F_MERCENARY;

void create()
{
	set_name("逄義", ({ "pangyi" }) );
	set("age", 33);
	set("race", "人類");
	set("long",
		"逄義是封山派中和柳淳風同輩的弟子，但是生性好賭的他並不受師父\n"
		"及同門師兄弟的喜愛，因此輩分雖高，卻未曾擔任門中任何重要職務\n"
		"。逄義經常外出，美其名曰：旅行，實則避債，礙於門規又不敢做那\n"
		"打家劫舍的勾當，因此經常四處尋找賺錢發財的機會。\n");
	set("max_force", 600);
	set("force", 1000);

	set("inquiry", ([
		"賺錢": "真的？哪裏有錢賺？",
		"發財": "發財我倒不敢想，只要有人肯僱用(employment)我，手邊有幾百兩銀子就好了。",
		"employment": "是的，一天一百兩銀子，只要不違背俠義道，我可以做任何事。",
		"柳淳風": "柳淳風是在下同門師兄。",
		"賭": ({ (: command, "hmm" :),
				 (: command, "grin" :),
				 "閣下如果也愛好此道，不如改天兄弟陪閣下玩幾手？" }),
	]) );
	create_family("封山劍派", 13, "弟子");
	set_skill("sword", 70);
	set_skill("dodge", 70);
	set_skill("unarmed", 80);
	set_skill("move", 80);
	set_skill("force", 65);
	set_skill("fonxanforce", 80);
	set_skill("fonxansword", 80);
	set_skill("chaos-steps", 70);
	set_skill("liuh-ken", 80);
	set_skill("literate", 60);
	map_skill("sword", "fonxansword");
	map_skill("unarmed", "liuh-ken");
	map_skill("dodge", "chaos-steos");
	map_skill("force", "fonxanforce");
	
	setup();

	carry_object("/obj/longsword")->wield();
	carry_object("/obj/cloth")->wear();
}

int accept_object(object me, object ob)
{
	if( query("on_duty") ) {
		command("say 對不起，在下目前已受人所僱，請過幾天再來。");
		return 0;
	}
	if( (int)ob->value() < 10000 ) {
		command("say 這 ... 閣下好意在下心領就是，請回吧。");
		return 0;
	}
	command("smile");
	command("say 太好了，閣下但有吩咐，逄某定當竭力以赴！");
	command("follow " + me->query("id"));
	set("boss_id", me->query("id"));
	set("on_duty", 1);
	call_out("duty_end", ((int)ob->value() / 10000) * 1440 );
	return 1;
}

void duty_end()
{
	object home;

	delete("on_duty");
	command("tell " + query("boss_id") + " 今天就到此爲止，承蒙閣下照顧，後會有期。");
	command("say 逄某告辭。");
	home = find_object(query("startroom"));
	if( home ) return_home(home);
	else destruct(this_object());
}

