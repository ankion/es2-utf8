// elder5.c

inherit NPC;

void create()
{
	set_name("南危水", ({ "nan weishuey", "nan", "weishuey" }) );
	set("title", "水煙閣五長老");
	set("gender", "男性");
	set("age", 52);
	set("long",
		"南危水是當世使劍的名家，也是槐陽王的弟弟，一身武學集天邪、封山\n"
		"兩派之所長，在水煙閣七長老中武功\僅次於二長老莫謙容。南危水手中\n"
		"的焦殤劍也是一把罕見的利器，傳說這把劍是名鑄劍師黃炎炎生平六把\n"
		"名劍中排名第一的傑作。\n");

	set("attitude", "peaceful");
	set("combat_exp", 800000);
	set("score", 120000);

	set("str", 25);
	set("cor", 30);
	set("cps", 30);
	set("con", 27);

	set("force", 1800);
	set("max_force", 1800);
	set("force_factor", 3);

	set("chat_chance_combat", 90);
	set("chat_msg_combat", ({
		(: perform_action, "sword.counterattack" :),
		(: exert_function, "powerup" :),
		(: exert_function, "recover" :),
	}) );

	set_skill("force", 100);
	set_skill("unarmed", 95);
	set_skill("sword", 100);
	set_skill("parry", 80);
	set_skill("dodge", 95);

	set_skill("celestial", 100);
	set_skill("celestrike", 90);
	set_skill("fonxansword", 100);

	map_skill("force", "celestial");
	map_skill("unarmed", "celestrike");
	map_skill("sword", "fonxansword");
	map_skill("parry", "fonxansword");

	setup();

	carry_object(__DIR__"obj/sorrowfire")->wield();
	carry_object("/obj/cloth")->wear();
	add_money("silver", 30);
}
