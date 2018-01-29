// worker.c

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("賣花姑娘", ({ "flower seller", "seller" }) );
        set("gender", "女性" );
        set("age", 19);
        set("per", 40);
        set("long", "美麗的賣花姑娘正在向行人售花兒\n");
        set("combat_exp", 700);
        set("attitude", "friendly");
        set_skill("unarmed", 40);
        set_skill("parry", 25);
        set_skill("dodge", 150);
        set_skill("throwing", 100);

        set("inquiry", ([
                "小娟" : "這要到黑松山去問。", 
        ]) );
        set("chat_chance", 5);
        set("chat_msg", ({
                (:random_move :)
        }) );
        set("vendor_goods", ([
                "purple flower": __DIR__"obj/purple_flower",
                "red flower": __DIR__"obj/red_flower",
                "yellow flower": __DIR__"obj/yellow_flower",
                "blue flower": __DIR__"obj/blue_flower",
                "white flower": __DIR__"obj/white_flower",
                "black flower": __DIR__"obj/black_flower",
        ]) );

        setup();
        add_money("silver", 15);
        carry_object("/obj/cloth")->wear();
        carry_object(__DIR__"obj/flower")->wield();
        carry_object(__DIR__"obj/flower")->wield();
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
        switch( random(6) ) {
                case 0:
                        say( " 賣花姑娘笑着道：這位"
                                + RANK_D->query_respect(ob)
                                + "，買朵黑牡丹嗎？ \n");
                        break;
                case 1:
                        say( " 賣花姑娘笑着道：這位"
                                + RANK_D->query_respect(ob)
                                + "，買朵黃枚瑰嗎？ \n");
                        break;
                case 2:
                        say( " 賣花姑娘笑着道：這位"
                                + RANK_D->query_respect(ob)
                                + "，買朵白茶花嗎？ \n");
                        break;
                case 3:
                        say( " 賣花姑娘笑着道：這位"
                                + RANK_D->query_respect(ob)
                                + "，買朵紫羅蘭嗎？ \n");
                        break;
                case 4:
                        say( " 賣花姑娘笑着道：這位"
                                + RANK_D->query_respect(ob)
                                + "，買朵紅枚瑰嗎？ \n");
                        break;
                case 5:
                        say( " 賣花姑娘笑着道：這位"
                                + RANK_D->query_respect(ob)
                                + "，買朵黃枚瑰嗎？ \n");
                        break;

        }
}


