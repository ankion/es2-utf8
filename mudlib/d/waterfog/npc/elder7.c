// watcher.c

inherit NPC;

void create()
{
	set_name("顏違", ({ "yen wei", "yen", "wei" }) );
	set("title", "水煙閣七長老");
	set("gender", "男性");
	set("age", 53);
	set("long",
		"顏違是水煙閣七位長老中最年輕的，雖然他的武功\跟其他六位長老\n"
		"相比仍略遜一籌，但是他辦事十分精明幹練，因此七長老每年都派\n"
		"他出外辦理武林大會事宜。\n");

	set("attitude", "peaceful");
	set("combat_exp", 270000);
	set("score", 36000);

	set("str", 25);
	set("cor", 23);
	set("cps", 23);
	set("con", 27);

	set("force", 1700);
	set("max_force", 1700);
	set("force_factor", 5);

	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: exert_function, "powerup" :),
		(: exert_function, "recover" :),
	}) );

	set_skill("force", 100);
	set_skill("unarmed", 80);
	set_skill("parry", 80);
	set_skill("dodge", 75);

	set_skill("celestial", 90);
	set_skill("celestrike", 80);

	map_skill("force", "celestial");
	map_skill("unarmed", "celestrike");

	setup();
}
