// room_guard.c
inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("保鏢", ({ "guard" }) );
        set("title", "貼身保鏢");
        set("gender", "男性" );
        set("age", 25);
        set("long", "你看到一個剽悍的大塊頭。\n");
        set("str", 29);
        set("int", 14);
	set("cor", 56);
	set("max_kee",800);
        set("combat_exp", 10000);
        set("attitude", "heroism");
        set_skill("unarmed", 200);
        set_skill("parry", 140);
        set_skill("dodge", 220);

        set("inquiry", ([
                "碧玉刀" : "這刀可是個寶物, 
據說是當年張家老祖宗退隱時皇上賜的。",
                "鎮關西" : "這雪亭鎮有誰不知道我家老爺鎮大官人！",
        ]) );
        setup();
        add_money("silver", 12);
        add_money("coin", 500);
        carry_object("/obj/cloth")->wear();
}

