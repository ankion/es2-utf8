// waiter.c

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("店小二", ({ "waiter" }) );
        set("gender", "男性" );
        set("age", 22);
        set("long",
"這位店小二正笑咪咪地忙著，還不時拿起掛在脖子上的抹布擦臉。\n"
	);

        set("combat_exp", 5);
        set("attitude", "friendly");
        set("rank_info/respect", "小二哥");
        set("vendor_goods", ([
                "cake":	__DIR__"obj/cake",
                "fish":	__DIR__"obj/fish",
                "wine":	__DIR__"obj/wine",
        ]) );
        setup();
}

void init()
{
        add_action("do_vendor_list", "list");
        add_action("go_up", "go");
}

int go_up (string arg)
{
        object me;

        me = this_player();

        if ( !me || environment(me) != environment() ) return 0;

        if( arg == "up" ) {
		if (!(me->query("rank")) && !(me->query("marks/酒樓"))) { 
			message_vision("店小二對$N一白眼:你是誰呀，闖什麼闖！\n",me);
			write("上樓的路被店小二擋住了 。\n");
			return 1;
			}
		    else {
			message_vision ("店小二高聲喊道:$N樓上請\n", me);
			me->move("/d/city/jiulou_2");
			return 1;
			}
	        }

        return 0;
}

int accept_object(object who, object ob)
{
        if ( ob->value() < 1000 ) {
                command("say 這點錢，還不夠買酒喝。");
                command("drop all");
                return 1;
	        }

        if ( !who->query("marks/酒樓") )  {
                if( ob->value() >= 1000 ) {
                        command("say 謝謝這位客官了。");   
                        who->set("marks/酒樓",1);
                        return 1;
                	}
                }
            else
                command("say 真是謝謝你了。\n");

        return 1;
}

