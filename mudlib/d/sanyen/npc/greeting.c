// greeting_bonze.c

inherit NPC;

void create()
{
	set_name("知客僧", ({ "greeting bonze", "bonze" }) );
	set("gender", "男性" );
	set("class", "bonze");
	set("age", 37);
	set("str", 26);
	set("cor", 22);
	set("cps", 26);
	set("int", 23);
	set("long",
		"這個知客僧臉色和藹，雖然在寺中的地位不高，但是他總是讓人有一種\n"
		"值得信賴的感覺。\n");
	set("combat_exp", 2000);
	set("attitude", "friendly");
	set("max_force", 300);
	set("force", 300);
	set("force_factor", 3);
	set_skill("force", 40);
	set_skill("unarmed", 40);
	set_skill("dodge", 40);
	setup();
}

int accept_fight(object me)
{
	command("say 阿彌陀佛！小僧武功\低微，認輸便是。\n");
	return 0;
}
