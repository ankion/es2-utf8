// shoer.c
inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("李掌櫃", ({ "seller" }) );
        set("title", "鞋店");
        set("gender", "女性" );
        set("age", 30);
        set("long", "李掌櫃是不難看的女人，一直經營着祖傳鞋店生意。\n");
        set("combat_exp", 220000);
        set("attitude", "friendly");
        set_skill("unarmed", 150);
        set_skill("dodge", 120);
        set_skill("sword", 120);

        set("inquiry", ([
                "鞋" : "您需要什麼樣的？",
        ]) );
       set("vendor_goods", ([
                "deer boots": __DIR__"obj/deer_boot",
                "elephant boots": __DIR__"obj/xiang_boot",
                "flower boots"  : __DIR__"obj/flower_boot",
        ]) );

        setup();
        add_money("gold", 9);
        add_money("coin", 300);
        carry_object("/obj/cloth")->wear();
        carry_object(__DIR__"obj/wuqing_sword")->wield();
}

void init()
{
        object ob;

        ::init();
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
                        say( "李掌櫃道：這位"
                                + RANK_D->query_respect(ob)
                                + "，您需要什麼樣的鞋？。\n");
                        break;
                case 1:
                        say( "李掌櫃白了你一眼，冷冷地說：你有美鈔嗎？\n");
                        break;
                case 2:
           say( "李掌櫃忽然間說道：好久沒去華工了，不知朋友是否還好嗎。\n");
                        break;
        }
}

