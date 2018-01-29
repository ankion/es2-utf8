// lm_guard.c

inherit NPC;

void create()
{
	set_name("綵衣少女", ({ "girl" }) );
	set("gender", "女性" );
	set("age", 16);
	set("str", 18);
	set("cor", 18);
	set("cps", 21);
	set("int", 25);
	set("per", 27);
	set("long", @LONG
    小姑娘是晚月莊的女弟子，雖說身形單薄，可眼神裏透出的傲氣讓
人感到並不好欺負。
LONG
);
	set("combat_exp", 1000);
	set("attitude", "heroism");
	set("chat_chance_combat", 15);
	set("chat_msg_combat", ({
		"少女說道：你當這裏是什麼地方，敢來這裏騷擾？\n",
		"少女說道：你要是再無理取鬧，當心莊主的鞭子！\n",
		"少女手中的鞭子越舞越快，讓你應接不暇。\n",
		"少女說道：你當晚月莊的女子好欺負麼？！\n"
	}) );
	set("inquiry", ([
		"藍止萍": "莊主的名字也是你這等人隨便叫的麼？",
		"晚月莊": "莊主吩咐過，不許亂講。",
	]) );

	set_skill("whip", 40);
	set_skill("parry", 20);
        set_skill("dodge", 40);
	
        set_skill("stormdance", 40);
        set_skill("snowwhip", 30);

        map_skill("dodge", "stormdance");
        map_skill("whip", "snowwhip");

	setup();
	
	carry_object("/u/cloud/obj/npc/lm_guard/whip")->wield();
	carry_object("/u/cloud/obj/npc/lm_guard/color_cloth")->wear();
}

