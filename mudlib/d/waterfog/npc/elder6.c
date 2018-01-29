// elder6.c

inherit NPC;

void create()
{
	set_name("陳堅石", ({ "chen jenxi", "chen", "jenxi" }) );
	set("title", "水煙閣六長老");
	set("gender", "男性");
	set("age", 57);
	set("long",
		"陳長老本來的名字已經沒有人知道了，但是他的橫練功\夫「石猿功\」成名\n"
		"數十年，加上個性有點....那個....頑固，因此水煙閣執法使潘軍禪給他\n"
		"起了個綽號叫「堅石」，久而久之陳長老倒也挺喜歡這個名字，索性捨棄\n"
		"了原來的名字改名叫陳堅石。\n");

	set("attitude", "peaceful");
	set("combat_exp", 360000);
	set("score", 75000);

	set("str", 25);
	set("cor", 23);
	set("cps", 23);
	set("con", 27);

	set("force", 1700);
	set("max_force", 1700);
	set("force_factor", 5);

	set("chat_chance_combat", 90);
	set("chat_msg_combat", ({
		(: exert_function, "powerup" :),
		(: exert_function, "recover" :),
	}) );

	set_temp("apply/armor", 100);

	set_skill("force", 100);
	set_skill("unarmed", 95);
	set_skill("staff", 100);
	set_skill("parry", 80);
	set_skill("dodge", 95);

	set_skill("celestial", 90);
	set_skill("celestrike", 80);

	map_skill("force", "celestial");
	map_skill("unarmed", "celestrike");

	setup();

	carry_object("/d/waterfog/obj/iron_staff")->wield();
}
