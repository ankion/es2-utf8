// cucurbit_seller.c

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("賣糖葫蘆的", ({ "cucurbit chapman", "chapman" }) );
	set("gender", "男性" );
	set("age", 42);
	set("combat_exp", 30);
	set("attitude", "friendly");
	set("vendor_goods", ([
	      "sugar cucurbit":__DIR__"obj/cucurbit",
	]) );
	set("chat_chance", 15);
	set("chat_msg", ({
		"賣糖葫蘆的吆喝道：糖葫蘆！好甜好香的糖葫蘆！\n",
	}) );
	set("inquiry", ([
		"糖葫蘆" : (: do_vendor_list :),
	]) );
	setup();
}

void init()
{	
	::init();

	add_action("do_vendor_list", "list");
}

