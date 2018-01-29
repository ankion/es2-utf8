// little_tiger.c

inherit NPC;

void create()
{
	set_name("小天邪虎", ({ "little tiger", "tiger" }) );
	set("long",
		"這是一隻天邪派的靈獸「天邪虎」，火紅的毛皮上有著如白銀般的\n"
		"白紋，然而這隻天邪虎的年紀顯然還很小，說不定還不到兩歲。\n");

	set("race", "野獸");
	set("age", 1);
	set("attitude", "friendly");

	set("max_gin", 300);
	set("max_kee", 300);
	set("max_sen", 100);

	set("str", 26);
	set("con", 36);
	set("cor", 20);
	set("spi", 30);
	set("int", 60);
	set("cps", 25);
	set("per", 60);
	set("kar", 70);

	set("limbs", ({ "頭部", "身體", "前腳", "後腿", "尾巴" }) );
	set("verbs", ({ "bite", "claw" }) );

	set_temp("apply/attack", 20);
	set_temp("apply/damage", 20);
	set_temp("apply/armor", 10);

	set("combat_exp", 2000);
	setup();
}
