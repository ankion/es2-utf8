// box_boss.c

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("林三爺", ({ "boxboss", "lin" }) );
        set("title", "棺材鋪老闆");
        set("gender", "男性" );
        set("age", 55);
        set("long", "這位面目慈善的老人經營棺材鋪已經有很多年了。\n");
        set("str", 29);
        set("int", 14);
	set("max_kee",800);

        set("combat_exp", 2000);
        set("attitude", "heroism");
        set_skill("unarmed", 60);
        set_skill("parry", 60);
        set_skill("dodge", 70);
	set_temp("apply/armor",20);

        set("inquiry", ([
                "棺材" : "您這麼年輕就要棺材，早了點吧？",
                "香茗坊" : "您也知道'碧海銀針'？茶樓就在街對面，我常去的。", 
        ]) );

        setup();
        add_money("silver", 4);
        add_money("coin", 100);
        carry_object("/obj/cloth")->wear();
}

