inherit NPC;
 
void create()
{
	object ob;

    set_name("藍雨梅", ({ "yu-may","yumay","may" }) );
	set("gender", "女性" );
	set("age",18);
	set("long", @TEXT
藍雨梅是晚月莊主藍止萍的養女，由於莊主不信任男子，因此
晚月莊接待外賓的工作向來由她負責。
TEXT
);
	set("per", 30);
	set("class", "dancer");
    set("combat_exp", 60000);

	set_skill("unarmed",60);
    set_skill("throwing", 90);
    set_skill("dodge", 70);
     set_skill("stormdance" , 30);
	set_skill("force",50);
     map_skill("dodge", "stormdance");

    set("force", 2000);
	set("max_force", 500);
	set("force_factor",2);

	set("chat_chance", 7);
	set("chat_msg", ({
        "藍雨梅微笑著說道：我們晚月莊是『 以舞會友，以神換技 』\n",
        "藍雨梅看你一臉疑惑！笑著說：我教你跳一曲『西出陽關』好嗎?\n",
		"藍雨梅微笑著說道：我跳支舞給您看好不好？\n",
        "藍雨梅微笑著說道：我的舞跳得不好，待會兒我請芳綾跳舞給您看，別走遠喔。\n"
	}) );
	set("inquiry", ([
		"西出陽關" : "『西出陽關』是一種幻影式舞步。可以移形換影。\n",
        "學舞" : "來!我教你...『西出陽關』(dancing out)是 ..... \n" +
               "經過雨梅指導後你漸漸懂了! \n",
		"舞" : "我會的舞是屬於「幻影式舞步」。\n",
		"芳綾" : "她是個可愛的女孩。不過有點任性，聽說她貪玩被關在 \n"+
                  "禁閉室。聽說她愛玩竹蜻蜓哦。\n",
		"竹蜻蜓" : "莊內有人會用竹子作成不同物品。\n",
        "滄海龍吟" : "是一種失傳以久的「寒谷龍舞」\n",
	]));
	create_family("晚月莊", 3, "大弟子");

	setup();
	ob = carry_object(__DIR__"obj/needle");
	ob->set_amount(30);
    ob->wield();
	carry_object(__DIR__"obj/deer_boot")->wear();
	carry_object(__DIR__"obj/skirt3")->wear();
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
    object teacup;
	if( !ob || environment(ob)!=environment() ) return;
	switch( random(2) ) {
		case 0:
			say( "雨梅對你微笑，和善的對你說：\n  這位" + 
				RANK_D->query_respect(ob)
				+ "，你好！歡迎來到晚月莊。請坐！\n");
			break;
		case 1:
            {
			say( "雨梅對你微笑，纖細的雙手捧著茶，\n 說道：這位" +
				RANK_D->query_respect(ob)
				+ "，你好！歡迎來到晚月莊。請用茶！\n");
             if ( ob->query_temp("latemoon/茶") ) 
                 command("smile");
                 else  {
                teacup = new("/d/latemoon/obj/teacup");
                teacup->move(ob);
                ob->set_temp("latemoon/茶", 1);
                say ("這是上等金軒茶!您品嚐一下。\n");
                   }
            }
		}
}
