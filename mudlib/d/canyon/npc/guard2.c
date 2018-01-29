// shiao.c

inherit NPC;

void create()
{
	set_name("老兵", ({ "guard" }) );
	set("gender", "男性");
	set("age", 24);
	set("long",
        	"風沙滿面，無精打采，毫無生氣的樣子，真難以想像是這\n"
                "□的守軍。\n");

	set("attitude", "peaceful");

	set("str", 26);
	set("int", 24);

	set("combat_exp", 40000);
	
	set("chat_chance", 15);
	set("chat_msg",({
		"老兵說道：軍師真是神算啊，把那狗賊都嚇的不敢再來了。\n",
		"老兵說道：聽說那個後備兵撿到了一個黃澄澄的寶物。\n",
		"老兵說道：嘿！有沒有錢啊？擋點□來花花吧！\n",
	}) );
	
	set("inquiry", ([
		"黃石隘口" : "這個問題問我們大隊長比較知道。\n",
		"後備兵" : "嘿嘿！你想做啥？\n",
		"軍火庫" : "你問這個喔..........不予回答。\n",
	]) );
	
	set("force", 300);
	set("max_force", 300);
	set("force_factor", 5);
	
	set_skill("unarmed", 40);
	set_skill("parry", 60);
	set_skill("dodge", 50);

	setup();

}
