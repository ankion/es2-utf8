// seller.c

inherit NPC;

void create()
{
	set_name("後備兵", ({ "guard" }) );
	set("gender", "男性" );
	set("age", 28);
	set("long",
		"環顧四方，眼神銳利，看來想殺價是不可能的事了。\n");
	set("combat_exp", 50000);
	set("attitude", "friendly");
	setup();
	
	carry_object( __DIR__"obj/blade")->wield();
}

int accept_object(object who,object ob)
{
	object obj1,obj2;



	who=this_player();
	
	if ( ob->value()==30000 ) {
		if ( this_player()->query_temp("Get_seal") ) {
			command("say 我已經給你了啊。");
			command("say 那麼多錢，那我就沒收了:P");
			return 1;
		}

		obj1=new(__DIR__"obj/fake_seal");
		if ( obj1->violate_unique() ) {
			command("say .......");
			command("say 內行人，你來晚一步了.. seal 被拿走了。");
			command("say 這東西你拿回去吧。");
			destruct(obj1);
			return 0;
		}

		command("say 不虧是武林中人，一眼就看出端倪了");
		command("say 這個印鑑就看在錢的份上和你交換了");
		obj1=new(__DIR__"obj/fake_seal");
		obj1->move(who);
        this_player()->set_temp("Get_seal", 1);
		return 1;
	}
	
	if ( !query_temp("check") ) {
		if ( ((string)ob->name() == "印鑑") && 
		     who->query_temp("將軍/kick") ) {
			command("say 好吧！即然被你發現了，只好認栽了。");
			command("say 這個真的你就拿去吧");
			obj2=new(__DIR__"obj/seal");
			obj2->move(who);
			who->delete_temp("將軍/kick");
			set_temp("check", 1);
			return 1;
		} else {
			command("say 你給我這個做什麼？我不要，你拿回去吧。");
			return 0;
		}
	} 
	command("say 如果是錢的話，我先沒收了。");
	command("say 其他的東西我都不要，別再來煩我了。");
	return 0;
}
			
	
