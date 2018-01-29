// doctor.c

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("夥計", ({ "waiter" }) );
        set("title", "藥店");
        set("gender", "男性" );
        set("age", 17);
        set("long", "藥店的小夥計，正在學着配藥。\n");
        set("combat_exp", 100);
        set("attitude", "heroism");
        set_skill("unarmed", 30);
        set_skill("parry", 10);
        set_skill("dodge", 10);

        set("inquiry", ([
		"抓藥" : "這裏是附近最好的藥店，您要什麼？",
        ]) );

        set("vendor_goods", ([
          "medicine": "/obj/drug/hurt_drug",
          "snake drug": "/obj/drug/snake_drug",
        ]) );

	setup();
	add_money("coin", 50);
        carry_object("/obj/cloth")->wear();
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
                        say( "小夥計稱了幾味藥，包做個紙包。\n");
                        break;
                case 1:
                        say( "夥計點頭道：這位"  
				+ RANK_D->query_respect(ob)
                                + "，買藥？\n");
                        break;
        }
}

