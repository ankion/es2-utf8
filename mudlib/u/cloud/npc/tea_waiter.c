// tea_waiter.c

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("茶博士", ({ "waiter" }) );
        set("gender", "男性" );
        set("age", 40);
        set("long",
                "茶博士正忙着招呼客人, 一手提着茶壺, 一手拿着抹布\n");
	set("combat_exp", 5);
        set("attitude", "friendly");
        set("rank_info/respect", "茶博士");
        set("inquiry", ([
                "香茗坊" : "這裏就是香茗坊呀! 客官。",
		"碧海銀針" : "您算是問着啦! 這可是百年的貢品啦，可惜...",
		"金匾"   : "這是當今皇上的高祖御筆親書的，好不威風!",
        ]) );

/*        set("vendor_goods", ([
                "茶葉": "/obj/example/dagger",
                "茶水": "/obj/example/wineskin",
                "茶壺": "/obj/example/dumpling",
                "茶杯": "/obj/example/chicken_leg",
        ]) );*/
        setup();
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
/*        add_action("do_vendor_list", "list");*/
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(3) ) {
                case 0:
                        say( "茶博士笑咪咪地說道：這位" + RANK_D->query_respect(ob)
                                + "，進來喝杯茶，歇歇腿吧。\n");
                        break;
                case 1:
                        say( "茶博士用毛巾抹了抹靠門的一張桌子，說道：這位" + RANK_D->query_respect(ob)
                                + "，請進請進。\n");
                        break;
                case 2:
                        say( "茶博士說道：這位" + RANK_D->query_respect(ob)
                                + "，進來嚐嚐才採的新茶葉。哇! 好香啊!...\n");
                        break;
        }
}

