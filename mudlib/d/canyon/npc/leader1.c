// leader.c

inherit NPC;

void create()
{
	set_name("小隊長", ({ "leader" }));
	set("gender", "男性");
	set("age", 30);
	set("long",
        	"不苟言笑的樣子，帶領著小兵駐守隘口的小隊長。\n");

	set("attitude", "peaceful");

	set("str", 27);
	set("int", 25);

	set("combat_exp", 80000);
	
	set("force", 400);
	set("max_force", 400);
	set("force_factor", 5);

	set_skill("dodge", 60);
	set_skill("sword", 60);
	set_skill("parry", 60);
	set_skill("force", 60);
	set_skill("unarmed", 65);
	
	setup();

	carry_object( __DIR__"obj/sword")->wield();
}

		
