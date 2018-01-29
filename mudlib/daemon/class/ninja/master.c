
// master.c
inherit NPC;
inherit F_MASTER;
void create()
 {
	set_name("逍遙子", ({ "master happyman", "happyman", "master" }) );
	set("nickname", "笑紅塵");
	set("gender", "男性" );
	set("age", 41);
	set("str", 27);
	set("cor", 30);
	set("cps", 20);
	set("int", 30);
	set("per", 30);
	set("con", 30);
	set("kar", 30);
	set("max_force", 2000);
	set("force", 2000);
	set("force_factor", 20);
	set("rank_info/respect", "無崖子");
	set("long",
		"逍遙子是個容貌俊美，風流倜儻的青年人，只看外表，你怎麼\n"
		"也猜不到他有４０歲了，只見他面如冠玉，一襲青衫更顯得瀟\n"
		"灑無比，一雙似笑非笑的眼睛，突然向你看了一眼，你不禁心\n"
		"中一動。\n");
	create_family("逍遙派", 4, "掌門人");
	set("combat_exp", 2000000);
	set("score", 300000);
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: exert_function, "recover" :),
		"紅塵多可笑，癡情最無聊\n",
		"憑誰知，多情總被無情惱\n",
		"對酒當歌，人生幾何\n",	}) );
        set_skill("unarmed", 150);
     	set_skill("parry", 120);
	set_skill("dodge", 150);
	set_skill("sword", 100);
	set_skill("force", 150);
	set_skill("literate", 150);
	set_skill("wu-shun", 120);
	set_skill("linbo-steps", 150);
	set_skill("ts-fist", 120);
	map_skill("unarmed", "ts-fist");
	map_skill("force", "wu-shun");
        map_skill("dodge", "linbo-steps");
	set("inquiry", ([
		"逍遙派" : "逍遙派門戶由我執掌，你有何指教？",
		"拜師"   : "入我派者，需人品文采，無一不是上上之選。",
         	"name": "我便是逍遙子，快樂逍遙，人生幾何。",
		"here": "這裏便是娘環福地。",	]) );
	        setup();
        	carry_object(__DIR__"seven_belt")->wear();
        	carry_object(__DIR__"green_dress")->wear();
      }
   
void attempt_apprentice(object ob)
 {
	if( ((int)ob->query("per") < 25)) 
          {     command("say 入我派者，需人品文采，無一不是上上之選。" +
              RANK_D->query_respect(ob) + "的資質不宜！");
               return; }
                         
        if (  ((int)ob->query_skill("literate",1) < 50) ) 
	  {	command("say 入我派者，需人品文采，無一不是上上之選。" + 
              RANK_D->query_respect(ob) + "的文采不宜！");
		return;	}

	if((string)ob->query("title")!="普通百姓")
       	 {
	    command("chat "+ob->query("title")+ob->query("nickname")+
            ob->query("name")+"要叛師！！！");	 
            command("grin");
	    kill_ob(ob);
	    return;
	 }

	command("smile");
	command("say 很好" + RANK_D->query_respect(ob) + 
        "多加努力他日必定有成。\n");
	command("recruit " + ob->query("id") );}
 
void recruit_apprentice(object ob)
         {
        	if( ::recruit_apprentice(ob) )
        	ob->set("class", "fighter");
        }
