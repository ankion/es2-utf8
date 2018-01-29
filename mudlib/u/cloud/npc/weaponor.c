// weaponor.c

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("兵器販子", ({ "weaponor" }) );
        set("title", "兵器屋");
        set("gender", "男性" );
        set("age", 32);
        set("long", "賣兵器的是個中年人，滿臉傷疤。\n");
        set("combat_exp", 20000);
        set("attitude", "friendly");
        set_skill("unarmed", 100);
        set_skill("dodge", 100);
        set_skill("sword", 60);

        set("inquiry", ([
                "兵器屋" : "本店專賣各種長短兵器", 
        ]) );

        set("vendor_goods", ([
                "whip": "/obj/weapon/whip",
                "sword": "/obj/weapon/longsword",
                "blade": "/obj/weapon/blade", 
                "dart": "/obj/weapon/dart",
                "leather shield": "/obj/weapon/shield",
                "sixhammer": "/obj/weapon/sixhammer",
                "thin sword": "/obj/weapon/thin_sword",
                "dagger": "/obj/weapon/dagger.c",
        ]) );

        setup();
        add_money("silver", 5);
        add_money("coin", 300);
        carry_object("/obj/cloth")->wear();
        carry_object("/obj/weapon/longsword")->wield();
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_vendor_list", "list");


}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(4) ) {
                case 0:
                        say( "兵器販子道：這位"
                                + RANK_D->query_respect(ob)
                                + "，自個兒挑一件稱手的兵器吧\n");
                        break;
                case 1:
                        say( "兵器販子突然間出了神，好象想起了他的往事\n");
                        break;
        }
}

