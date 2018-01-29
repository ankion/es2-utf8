// hermit1.c

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("賣包子的", ({ "dumpling seller", "seller" }) );
	set("gender", "男性" );
	set("age", 33);
	set("long", "這個賣包子的小販對你微微一笑，說道：熱騰騰的包子，來一籠吧？\n");
	set("combat_exp", 30);
	set("attitude", "friendly");
	set("vendor_goods", ([
	        "dumpling": "obj/example/dumpling",
           ]) );
	set("chat_chance", 15);
	set("chat_msg", ({
		"賣包子的吆喝道：包子！熱騰騰的包子！\n",
	}) );
	set("inquiry", ([
		"包子" : (: do_vendor_list :),
	]) );
	setup();
}

void init()
{	
	::init();

	add_action("do_vendor_list", "list");
}

