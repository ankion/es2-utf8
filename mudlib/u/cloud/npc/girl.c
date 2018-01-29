// girl.c

inherit NPC;

void create()
{
	set_name("李師師", ({ "girl" }) );
	set("title", "名妓");
	set("gender", "女性" );
	set("age", 22);
	set("str", 10);
	set("per", 30);
	set("long", @LONG
    李師師是怡紅院的名妓，精通琴棋書畫，周圍的紈絝子弟們常往這
裏鑽。
LONG
);
	set("combat_exp", 10);
	set("attitude", "friendly");

        set("chat_chance_combat", 25);
        set("chat_msg_combat", ({
"李師師秀眉微蹙，說道：喂！我哪裏得罪您了？幹嘛這樣跟我拼死拼活？\n",
	}) );

	set_skill("literate", 100);

	set("inquiry", ([
		"過夜": "官人可要潔身自好啊！",
		"嫖妓": "官人可要潔身自好啊！",
		"學藝": "請您留件信物！",
	]) );

	setup();
	
	carry_object("/u/cloud/obj/npc/girl/pink_cloth")->wear();
}

int recognize_apprentice(object ob)
{
        if( !ob->query("marks/李師師") ) {
                say("李師師說道：咦？我不記得您啊......\n");
                return 0;
        }
        return 1;
}

int accept_object(object who, object ob)
{
	if( ob->value() ){
		command("say 我對錢沒興趣！");
                return 0;
        }

	if( (this_player()->query("per") < 25) 
		|| ( (string)this_player()->query("gender") == "女性") ){
		command("say 我對您沒興趣！");
		return 0;
	}
	command("say 能做相公的老師，真是三生有幸。");
	who->set("marks/李師師", 1);
        return 1;
}

int accept_fight(object me)
{
	command("say 小女子哪裏是您的對手？");
	return 0;
}

