inherit NPC;

void create()
{
    set_name("金絲雀", ({ "sparrow" }) );
	set("race", "野獸");
	set("age", 1);
	set("gender", "雌性");
	set("long", "一隻翩翩起舞的小蝴蝶哦! \n");

    set("str", 20);

    set("combat_exp", 1000);
	set("attitude","peaceful");

	set("limbs", ({ "頭部", "身體","翅膀" }) );
    set("verbs", ({ "bite","claw" }) );
	set_temp("apply/dodge", 100);

    set("chat_chance", 7);
	set("chat_msg", ({
		(: random_move :),
        "小金絲雀嘰嘰的叫! \n",
        "金絲雀用嘴整理羽毛。 \n"
	}) );

	setup();
}
