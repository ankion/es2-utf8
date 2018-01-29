// seller.c

inherit NPC;
inherit F_VENDOR;

void create()
{
  set_name("潘若秋", ({ "seller" }) );
  set("title", "書局老闆");
  set("gender", "男性" );
  set("age", 32);
  set("long", "潘老闆長得很白淨，一副讀書人的老實相。\n");
  set("combat_exp", 5000);
  set("attitude", "friendly");
  set_skill("unarmed", 70);
  set_skill("dodge", 50);

  set("inquiry", ([
    "書局" : "爲讀書人辦點事也是盡一份心意。", 
  ]) );

  set("vendor_goods", ([
    "literate book": "/u/cloud/obj/literate_book",	
  ]) );

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
        add_action("do_vendor_list", "list");

}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(4) ) {
                case 0:
                        say( "潘若秋迎上來，說道："
                                + RANK_D->query_respect(ob)
                                + "可是來買書的？\n");
                        break;
                case 1:
                        say( "潘若秋幽幽地嘆了口氣，說道：“作個讀書人難啊！”。\n");
                        break;

		case 2:
			say( "潘若秋真聚精會神地看着書，似乎沒注意你的到來。\n");
			break;

        }
}

