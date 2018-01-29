//walker.c

inherit NPC;

void create()
{
        set_name("行人", ({ "walker" }) );
	set("age", 20 + random (45));
	
        switch (random (3)) {
		case 0:
			set("gender", "女性");
			break;
		default:	
			set("gender", "男性" );
			break;
		}

        set("combat_exp", 30000);
	if (random(4) == 0) {
		set_skill("unarmed", 40);
		set_skill("spicyclaw", 20);
		set_skill("parry", 40);
		map_skill("unarmed", "spicyclaw");
		}

        set("attitude", "friendly");
        set("chat_chance", random (20));
        set("chat_msg", ({
                "行人搖了搖頭，說：世事無常，只苦了我們這些老百姓。\n",
                "行人憤憤地說：這年頭，幾個臭錢就能買到官。哼！\n",
                "行人嘆了口氣：皇上太年幼了，朝廷就讓那個老不死的把持着。咳！\n",
		(: random_move :),
        }) );

        set("inquiry", ([
                "買官" : (: "全是那個該死的尚書作的孽。\n" :),
	        ]) );
        setup();
}

