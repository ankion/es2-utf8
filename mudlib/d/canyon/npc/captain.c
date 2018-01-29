// captain.c

#include <ansi.h>

inherit NPC;

string tell_story(object who);

string *make_msg = ({
    HIG"二十多年前，先帝將大將軍們調來這□駐守隘口。\n\n"NOR,
    HIG"京城的也就因隘口的鞏固而獲得安全。\n\n"NOR,
    HIG"事隔多年，先帝也死了，換上的是位我們不甚認識的小皇帝。\n\n"NOR,
    HIG"看來他只忙著找劍，也沒什麼大作爲，大家也不太服他。\n\n"NOR,
    HIG"皇帝看到大將軍還要敬畏三分ㄌㄟ。\n\n"NOR,
    HIG"反正啊，將軍和軍師是超強的，你可要好好的烏西我們才行。\n\n"NOR,
    HIG"知道了，就快繳錢。\n"NOR,
});

void create()
{
	set_name("大隊長", ({ "captain" }));
	set("gender", "男性");
	set("age", 30);
	set("long",
        	"他不苟言笑的樣子，帶領著小兵駐守隘口的隊長。\n");

	set("attitude", "peaceful");

	set("str", 27);
	set("int", 25);

	set("combat_exp", 120000);

	set("inquiry", ([
		"允許" : "先給錢再說吧。\n",
		"兵器庫" : "喔！那是我們厲害的軍師所設的陣法。\n",
		"黃石隘口" : (: tell_story :),
	]) );
	
	set("chat_chance", 8);
	set("chat_msg", ({
		"大隊長說道：有沒有問題要問我啊？\n",
		"大隊長說道：我對這□很熟的喔。\n",
	}) );
	
	set("force", 700);
	set("max_force", 700);
	set("force_factor", 5);

	set_skill("dodge", 70);
	set_skill("sword", 70);
	set_skill("parry", 70);
	set_skill("force", 70);
	set_skill("unarmed", 65);
	
	setup();

	carry_object( __DIR__"obj/sword")->wield();
	carry_object( __DIR__"obj/armor")->wear();
}

int accept_object(object who, object ob)
{
        if ( !ob->value() ) {
        	command("say ㄟ....Ｔhank Ｙou!!!");
                command("grin");
        //        call_out( (: destruct :), 1, ob);
                return 1;
        }
                                                                                
	if ( !who->query("marks/軍營") ) {
		if( ob->value() >=3000 ) {
			say("大隊長說道:我已幫你列入名冊了，從今天你可自由"
				"地出入營區了。\n");
			who->set("marks/軍營",1);
			return 1;
		} else {
			say("大隊長說道:你的誠意不夠喔，再多繳點吧。\n");
			return 1;
		}
	} else
		say("大隊長說道:哦喔！還真有心啊，真是謝謝你了。\n");
	
	return 1;
}

string tell_story(object who)
{
	who=this_player();
	call_out( "make_stage", 2, who, 0 );
	return 0;
}

void make_stage(object who,int stage)
{
	tell_object(who,make_msg[stage]);
	if (++stage < sizeof(make_msg) ) {
		call_out( "make_stage", 2, who, stage);
		return;
	}
	return;
}
         
		
