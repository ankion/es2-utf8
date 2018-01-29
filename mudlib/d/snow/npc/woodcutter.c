// woodcutter.c

inherit NPC;

void create()
{
	set_name("樵夫", ({ "woodcutter" }) );
	set("gender", "男性" );
	set("age", 26);
	set("long", "你看到一個粗壯的大漢，身上穿著普通樵夫的衣服。\n");
	set("combat_exp", 140);
	set("str", 30);
	set("chat_chance", 15);
	set("chat_msg", ({
		"樵夫說道：野羊山那羣臭道士真是該千刀萬剮....\n",
		"樵夫說道：不知道那些牛鼻子施了什麼妖法，前天回家差點迷了路。\n",
		"樵夫說道：唉....日子越來越不好過羅。\n",
		(: random_move :)
	}) );
	set("env/wimpy", 10);
	setup();
	carry_object(__DIR__"obj/lumber_axe")->wield();
	carry_object("/obj/cloth")->wear();
}
