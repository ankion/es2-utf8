// keeper.c

inherit NPC;

void create()
{
	set_name("廟祝", ({ "keeper" }) );
	set("gender", "男性" );
	set("age", 74);
	set("long",
		"這個老人看起來七十多歲了，看著他□僂的身影，你忽然覺得心情沈重了下來。\n");
	set("combat_exp", 1);
	set("attitude", "friendly");
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
}

void greeting(object ob)
{
	if( !ob || !present(ob, environment(this_object())) ) return;
	say( "廟祝說道：這位" + RANK_D->query_respect(ob)
		+ "，捐點香火錢積點陰德吧。\n");
}

/*int accept_object(object who, object ob)
{
	say( "廟祝說道：這位" + RANK_D->query_respect(who)
		+ "，請把香油錢投入功\德箱。\n");
	return 0;
}*/
int accept_object(object who, object ob)
{
        int val;

        val = ob->value();
        if( !val )
                return notify_fail("廟祝不收物品的捐獻。\n");
        else if( val > 100 ) {
                if( (who->query("bellicosity") > 0)
                &&      (random(val/10) > (int)who->query("kar")) )
                        who->add("bellicosity", -
(random((int)who->query("kar")) + val/1000) );
        }
        say( "廟祝說道：多謝這位" + RANK_D->query_respect(who)
                + "，神明一定會保佑你的。\n");

        return 1;
}


