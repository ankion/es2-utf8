inherit NPC;

void create()
{
     set_name("小白兔", ({ "rabbit" }) );
	set("race", "野獸");
	set("age", 1);
	set("gender", "雌性");
     set("long", "一隻紅眼睛的小白兔。\n");

    set("str", 20);

    set("combat_exp", 1000);
	set("attitude","peaceful");

     set("limbs", ({ "頭部", "身體","前腳","後腿" }) );
    set("verbs", ({ "bite","claw" }) );
    set_temp("apply/dodge", 30);

    set("chat_chance", 7);
	set("chat_msg", ({
		(: random_move :),
        "小白兔蹦蹦跳跳的。\n",
        "小白兔用嘴舔前肢。 \n"
	}) );

	setup();
}
