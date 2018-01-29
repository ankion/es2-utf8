// mother.c

inherit NPC;

void create()
{
	set_name("鴇母", ({ "mother" }) );
	set("gender", "女性" );
	set("age", 49);
	set("str", 10);
	set("per", 26);
	set("long", @LONG
    鴇母是個濃妝豔抹的中年女子，身材微胖，全身上下珠光寶氣。
LONG
);
	set("combat_exp", 10);
	set("attitude", "friendly");

	set_skill("unarmed", 100);
	set_skill("parry", 50);

	set("chat_chance_combat", 15);
	set("chat_msg_combat", ({
		"鴇母說道：你當這裏是什麼地方，敢來這裏騷擾？\n",
	}) );
	set("inquiry", ([
		"怡紅院": "哎呀！就是我們這裏啊，您裏面請",
	]) );

	setup();
	
	carry_object("/u/cloud/obj/npc/lm_guard/color_cloth")->wear();
	carry_object("/obj/toy/poison_dust.c");
}

