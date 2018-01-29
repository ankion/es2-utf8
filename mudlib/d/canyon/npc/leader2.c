// leader.c

inherit NPC;

void create()
{
	set_name("老隊長", ({ "leader" }));
	set("gender", "男性");
	set("age", 30);
	set("long",
        	"不苟言笑的樣子，帶領著小兵駐守隘口的小隊長。\n");

	set("attitude", "peaceful");

	set("str", 27);
	set("int", 25);

	set("combat_exp", 80000);
	
	set("chat_chance", 8);
	set("chat_msg", ({
	"老隊長說道：大隊長對這個地方好熟，還常常說些這□的故事給我們聽。\n",
	"老隊長說道：你有沒有搞錯啊！來這□不給我們大隊長過路費，你找死啊！\n",
	"老隊長說道：兵器庫入口處的陣法真是厲害，一般人絕對找不到的。\n",
	}) );
	
	set("inquiry", ([
		"黃石隘口" : "你問問大隊長吧，我不是很清楚。\n",
		"後備兵" : "後備兵就..........你想做什麼？找死啊。\n",
	]) );
	
	set("force", 400);
	set("max_force", 400);
	set("force_factor", 5);

	set_skill("dodge", 60);
	set_skill("blade", 60);
	set_skill("parry", 60);
	set_skill("force", 60);
	set_skill("unarmed", 65);
	
	setup();

	carry_object( __DIR__"obj/blade")->wield();
}

		
