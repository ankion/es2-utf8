// guard.c
#include <ansi.h>

string kill_passenger(object who);

inherit NPC;

void create()
{
        set_name("京師守城兵", ({ "City guard", "guard" }) );
        set("long",
          "這是個正在這裏站崗的京師官兵，雖然和許多武林人物比起來，官兵\n"
          "們的武功實在稀鬆平常，但是他們是有組織、有紀律的戰士，誰也不\n"
          "輕易地招惹他們。\n");

        set("attitude", "peaceful");
        set("vendetta_mark", "authority");

        set("str", 27);
        set("cor", 26);
        set("cps", 25);

        set("attitude", "peaceful");
        set("vendetta_mark", "authority");

        set("str", 27);
        set("cor", 26);
        set("cps", 25);

        set("combat_exp", 100000);

        set("chat_chance_combat", 15);
        set("chat_msg_combat", ({
                "守城官兵喝道：還不快放下武器束手就縛？\n",
                "守城官兵喝道：大膽刁民！竟敢在天子腳下造反？\n"
        }) );

        set("inquiry",  ([
                "出城":
                        "你可以在京城裏找一找，說不定可以找到一些出城的令牌。\n",
               "out":
                       "你可以在京城裏找一找，說不定可以找到一些出城的令牌。\n",
                ]) );

        set_skill("unarmed", 90);
        set_skill("sword", 90);
        set_skill("parry", 90);
        set_skill("dodge", 90);
        set_skill("move", 100);

        set_temp("apply/attack", 90);
        set_temp("apply/defense", 90);
        set_temp("apply/damage", 40);
        set_temp("apply/armor", 90);
        set_temp("apply/move", 100);

        setup();
        carry_object("/obj/cloth")->wear();
        carry_object("/obj/longsword")->wield();
}

void init()
{
//        add_action("do_out", "out");
	add_action("do_kill","kill");
//	add_action("go_out", "go");
}
/*
int do_out()
{
        object me;
        me = this_player();
             if( !me->query("marks/京師") )
             {
                command("say 沒有官府通令，任何人不能出入京師。");
                write("出城方向的路被京師守城兵擋住了 。\n");
                return 1;
             }
             else
                return 0;
}

int go_out(string arg)
{
        object me;
        me = this_player();
        if( arg == "out" )
        {
             if( !me->query("marks/\101\156\105\106") )
             {
                command("say 沒有官府通令，任何人不能出入京師。");
                write("出城方向的路被京師守城兵擋住了 。\n");
		return 1;
             }
             else
                return 0;
        }
        return 0;
}
*/
int do_kill(string arg)
{
        object me;
        me = this_player();
        if( arg == "guard" )
        {
	   kill_ob(me);
           return notify_fail( "守城兵大叫：反了！反了！" );
        }
        return 0;
}

int accept_object(object who, object ob)
{
//        if ( (string)ob->name() != "官府通令")
	if ( ob->query("id") != "token") 
        {
                command("say 這是什麼東西啊！你想偷渡呀？");
                return 0;
        }

//        if ( !who->query("marks/京師") ) 
//	{
                say("京師守城兵連忙說道：原來是官府中人，您請出城。\n");
                who->set("marks/令牌",1);
//                return 1;
//	}
	
	ob->destruct();
        return 1;
}

