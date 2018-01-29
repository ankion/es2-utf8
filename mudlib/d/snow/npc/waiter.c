// waiter.c

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("店小二", ({ "waiter" }) );
	set("gender", "男性" );
	set("age", 22);
	set("long",
		"這位店小二正笑咪咪地忙著，還不時拿起掛在脖子上的抹布擦臉。\n");
	set("combat_exp", 10000);
	set_skill("dodge", 300);
	set("attitude", "friendly");
	set("rank_info/respect", "小二哥");
	set("vendor_goods", ([
		"dagger": "/obj/example/dagger",
		"wineskin": "/obj/example/wineskin",
		"dumpling": "/obj/example/dumpling",
		"chicken leg": "/obj/example/chicken_leg",
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
	switch( random(3) ) {
		case 0:
			say( "店小二笑咪咪地說道：這位" + RANK_D->query_respect(ob)
				+ "，進來喝杯茶，歇歇腿吧。\n");
			break;
		case 1:
			say( "店小二用脖子上的毛巾抹了抹手，說道：這位" + RANK_D->query_respect(ob)
				+ "，請進請進。\n");
			break;
		case 2:
			say( "店小二說道：這位" + RANK_D->query_respect(ob)
				+ "，進來喝幾盅小店的紅酒吧，這幾天才從窖子裏開封的喲。\n");
			break;
	}
}

void relay_say(object ob, string msg)
{
	object cake;

	if( (strsrch(msg,"ES2")>=0 || strsrch(msg, "es2")>=0) && strsrch(msg,"生日快樂")>=0 ) {
		command("jump");
		command("say 生日快樂!");
		seteuid(getuid());
		if( !present("cake", ob) ) {
			cake = new("/obj/example/cake");
			cake->move(ob);
			message_vision("$N給$n一塊看起來就令人流口水的蛋糕。\n", this_object(), ob);
		}
	}
}
