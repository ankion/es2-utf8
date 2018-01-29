// judge_guard.c

inherit NPC;

void create()
{
	set_name("衙役", ({ "judge guard","guard" }) );
	set("gender", "男性" );
	set("age", 24);
	set("str", 18);
	set("cor", 18);
	set("cps", 21);
	set("int", 25);
	set("per", 27);
	set("long", @LONG
衙役精明強幹, 滿臉正氣. 
LONG
);
	set("combat_exp", 8000);
	set("attitude", "heroism");
	set("chat_chance_combat", 15);
	set("chat_msg_combat", ({
		"衙役說道：你當這裏是什麼地方，敢來這裏騷擾？\n",
		"衙役說道：你要是再無理取鬧，當心捕頭把你抓去坐牢!\n",
		"衙役手中的刀越砍越快，讓你應接不暇。\n",
		"衙役說道：衙門豈是你放肆的地方？！\n"
	}) );

	set_skill("staff", 40);
	set_skill("unarmed", 40);
        set_skill("dodge", 80);
        set_skill("liuh-ken", 80);	
        set_skill("fall-steps", 80);
        map_skill("unarmed", "liuh-ken");
        map_skill("dodge", "fall-steps");

	setup();
	
}

