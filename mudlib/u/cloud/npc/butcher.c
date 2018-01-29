// butcher.c

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("鄭屠夫", ({ "butcher", "zheng" }) );
        set("title", "鎮北肉鋪");
        set("gender", "男性" );
        set("age", 35);
        set("long", "你看到一個剽悍的大塊頭, 正在用鋼刀剔牛骨。\n");
        set("str", 29);
        set("int", 14);
        set("combat_exp", 2500);
        set("attitude", "heroism");
        set_skill("unarmed", 100);
        set_skill("parry", 100);
        set_skill("dodge", 100);

        set("inquiry", ([
                "碧玉刀" : "這刀可是個寶物, 
據說是當年張家老祖宗退隱時皇上賜的。",
                "香茗坊" : "您也知道'碧海銀針'？茶樓就在街對面，我常去的。", 
        ]) );

        set("vendor_goods", ([
                "beef": "/u/cloud/obj/meat/b_beef",
                "hind": "/u/cloud/obj/meat/hind",
                "tail": "/u/cloud/obj/meat/tail",
                "fragment": "/u/cloud/obj/meat/zasui",
                "dog meat": "/u/cloud/obj/meat/dog_m",
        ]) );

        setup();
        add_money("silver", 12);
        add_money("coin", 500);
        carry_object("/obj/cloth")->wear();
        carry_object("/u/cloud/obj/npc/butcher/knife");
        carry_object("/u/cloud/obj/npc/butcher/skin_belt")->wear();
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
                        say( "屠夫邊剔骨頭邊嘟囔着：真是好刀，剔得好舒服! 
\n");
                        break;
                case 1:
                        say( "屠夫搖搖頭, 嘆了口氣說：唉, 不知那碧玉刀究竟"
                                +"比我這刀厲害幾倍...\n");
                        break;
                case 2:
                        say( "屠夫咧開大嘴, 笑着道：這位"  
                                + RANK_D->query_respect(ob)
                                + "，要買肉是嗎? \n");
                        break;
                case 3:
                        say( "屠夫忙着給人取肉, 似乎沒注意到你進來。\n");
                        break;
        }
}

 
