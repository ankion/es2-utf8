// guard.c
#include <ansi.h>

inherit NPC;

void create()
{
        set_name("門房", ({ "guard" }) );
        set("id", "guard");
	set("long",
		"尚書府的門房雖然沒什麼官銜，但所有想晉見\n"
		"尚書的白衣無不對他畢恭畢敬的n"
		);

        set("attitude", "peaceful");

        set("str", 27);
        set("cor", 26);
        set("cps", 25);

	set("combat_exp", 1000);

        set("chat_chance", 5);
	set("chat_msg", ({
        	"門房慢吞吞地說：是。。想見尚書大人的嗎？。。\n",
		"門房嘿嘿地笑了笑，手裏比劃着一個數字.\n"
		}) );

        set_skill("unarmed", 90);
        set_skill("parry", 60);
	set_skill("dodge", 90);

        setup();
        carry_object("/obj/cloth")->wear();
}

int accept_object(object who, object ob)
{
        if ( !who->query("marks/尚書") ) {
                if( ob->value() >=30000 ) {
                        say("門房說道:這位大人，裏面請！\n"); 
                        who->set("marks/尚書",1);
                        return 1;
			}  
	           else {
       		         say ("鼻子裏哼了一聲，頭掉了過去。\n"); 
			 return 1;
       			 }
		}

	else {
		say ("大人太客氣了\n");
        	return 1;
		}
}

