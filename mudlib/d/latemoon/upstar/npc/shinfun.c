inherit NPC;
string do_reply();
 
void create()
{
        set_name("莫欣芳" , ({ "shinfun","fun","girl" }) );
        set("gender", "女性" );
        set("age", 27);
        set("long", @TEXT
她國色天香，嬌麗無倫；溫柔嫺靜，秀絕人寰。
她姿容絕美，世所罕見。從她身旁你聞道一寒谷
幽香。
TEXT
);
	set("inquiry", ([
		"舞曲譜":
		(: this_object(), "do_reply" :),
	]) );
       set("class", "dancer");
       set("combat_exp", 200000);
        set_skill("unarmed", 50);
        set_skill("dodge", 70);
        set_skill("stormdance", 50);
        set_skill("tenderzhi", 70);
        set_skill("force",50);
        map_skill("dodge","stormdance");
        map_skill("unarmed","tenderzhi");
        set("force", 1000);
        set("max_force", 500);
       set_temp("apply/armor", 70);
       set_temp("apply/attack", 50);

        create_family("晚月莊",2,"弟子");
        setup();
        carry_object("/d/latemoon/obj/deer_boot")->wear();
        carry_object("/d/latemoon/obj/belt")->wear();
        carry_object("/d/latemoon/obj/clasp")->wear();
}

string do_reply()
{
	this_player()->set("mark/dance-book",1);
	return("舞曲譜啊，師姐她們練習舞步的時候才用的着，\n"+
"你也想學嗎？ 嘻嘻...\n");
}

