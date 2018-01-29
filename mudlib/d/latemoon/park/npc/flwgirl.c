// flowergirl.c

inherit NPC;

void create()
{
	set_name("採花少女", ({ "girl" }) );
	set("gender", "女性" );
	set("age", 15);
	set("per", 30-random(15) );
        	set("long", 
		"採花少女是綺雲鎮居民的小孩，從小就到晚月莊來摘桂花，藍止\n"
		"萍很喜歡她們，也教給她們了些基本的武功，時間久了，這些少\n"
		"女的功夫還都不錯。\n"
	);
	set("combat_exp", 20000);
	set("attitude", "friendly");
         	set("chat_chance", 4);
       	set("chat_msg", ({
"頑皮的採花少女向你扮個鬼臉。  *^G^* \n",
"採花少女說道：華中理工大學的桂花樹比晚月莊多多了，你知道嗎？\n",
"採花少女望着天邊的晚霞，雙手託着香腮，說道：我好想去華工大摘桂花。\n",
"採花少女嘀咕着：聽說華工的桂花有好幾種呢。\n",
       }) );

        	set("chat_chance_combat", 10);
        	set("chat_msg_combat", ({
"採花少女秀眉微蹙，說道：你欺負我年紀小是嗎？\n",
"採花少女說道：你要是再無理取鬧，讓火玫瑰毒死你！\n",
"採花少女罵道：你這無賴，別死纏着我！\n",
        	}) );
	set("inquiry", ([
		"桂花" : "華中理工大學的桂花樹比晚月莊多多了，你知道嗎？",
	]) );

	set_skill("parry", 30);
	set_skill("dodge", 70);
	set_skill("unarmed", 120);
	set_skill("throwing", 150);
       	set_skill("stormdance", 45);

        map_skill("dodge", "stormdance");
        set_skill("force", 15);
        set("force", 500);
        set("max_force", 500);
        set("force_factor", 0);

	setup();
        	carry_object("/u/cloud/obj/npc/girl/pink_cloth")->wear();
        	for(int i=1; i<=2; i++){
	carry_object("/d/latemoon/park/npc/obj/guihua")->wield();
        	}
}


