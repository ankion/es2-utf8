// weaponor.c
inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("萬曉生", ({ "weaponor" }) );
        set("title", "武器店掌櫃");
        set("gender", "男性" );
        set("age", 52);
        set("long", "萬曉生是個鬚髮皆白的老人，闖蕩江湖已近五十年。\n");
        set("combat_exp", 120000);
        set("attitude", "friendly");
        set_skill("unarmed", 100);
        set_skill("dodge", 100);
        set_skill("sword", 100);

        set("inquiry", ([
                "武器" : "本店專賣各種長短兵器",
        ]) );
       set("vendor_goods", ([
		"紫銅戰盔": __DIR__"obj/armor1",
                "rain whip"  : __DIR__"obj/rain_whip",
                "cool sword"  : __DIR__"obj/wuqing_sword",
                "duoqing blade"  : __DIR__"obj/duoqing_blade",
                "demon staff"  : __DIR__"obj/demon_staff",
                "leather shield"  : "/obj/weapon/shield",
                "sixhammer"  : "/obj/weapon/sixhammer",
                "thin sword"    : "/obj/weapon/thin_sword",
                "dagger"    : "/obj/weapon/dagger",
        ]) );

        setup();
        add_money("silver", 50);
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
                        say( "萬曉生道：這位"
                                + RANK_D->query_respect(ob)
                                + "，自個兒挑一件稱手的兵器吧。\n");
                        break;
                case 1:
                        say( "萬曉生冷冷地說：客官請付現鈔。\n");
                        break;                       
                case 2:
say( "萬曉生忽然間似乎想起了遠在美國的朋友和當年同闖江湖的情形。\n");
                        break;
        }
}

