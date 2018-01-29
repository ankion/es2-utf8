// fisher.c

inherit NPC;

void create()
{
	set_name("漁夫", ({ "fisher" }) );
	set("gender", "男性" );
	set("age", 35);
       	set("long", @LONG 
一個精壯的漢子，頭戴斗笠，身披蓑衣。偶爾擡頭一看的眼神
中精光大盛，很有可能是江湖中人。
LONG
);
	set("combat_exp", 20000);
	set("attitude", "friendly");
        set("chat_chance", 2);
       	set("chat_msg", ({
"漁夫嘀咕着：不知這水怪又吃了幾個人。\n",
       }) );

        set("chat_chance_combat", 10);
        set("chat_msg_combat", ({
"有種的去殺了那水怪，打我算什麼英雄？！\n",
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
	carry_object("/obj/cloth")->wear();

}
