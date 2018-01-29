inherit NPC;

void create()
{
        set_name("丫鬟", ({ "maid" }) );
        set("long",
		"她是尚書府的司職廚務的丫鬟，一年四季呆在廚房中。但粗重的\n"
		"雜活也掩不住其天生麗質。\n"
                );

        set("attitude", "peaceful");

        set("gender", "女性");
	set("age", 19);
	set("per", 27);

        set("combat_exp", 1000);

        setup();
        carry_object(__DIR__"obj/pink_cloth")->wear();
}


