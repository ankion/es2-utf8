// tailor.c

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("裁縫", ({ "tailor" }) );
        set("title", "布莊");
        set("gender", "男性" );
        set("age", 42);
        set("long", "一位看上去很和藹的老裁縫，正在縫製衣服。\n");
	set("str", 12);
	set("int", 24);
        set("combat_exp", 500);
        set("attitude", "friendly");
        set_skill("sword", 30);
        set_skill("parry", 30);
        set_skill("dodge", 30);

        set("inquiry", ([
		"香茗坊" : "您也知道'碧海銀針'？茶樓就在斜對面，我常去的。", 
        ]) );

        set("vendor_goods", ([
                "cloth": "/u/cloud/obj/cloth/cloth",
        ]) );

	setup();
	add_money("silver", 2);
	add_money("coin", 50);
        carry_object("/obj/cloth")->wear();
	carry_object("/u/cloud/obj/npc/tailor/ruler");
	carry_object("/u/cloud/obj/npc/tailor/scissors")->wield();
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
                        say( "老裁縫擡起頭看了你一眼，問道：客官買布還是製衣?\n");
                        break;
                case 1:
                        say( "裁縫的手腳甚是麻利，顯然已做了多年了。\n");
	}
}

