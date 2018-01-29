// master.c

inherit NPC;
inherit F_MASTER;
void create()
{
	set_name("絕塵子",({"master outer","master","outer"}) );
	set("gender","男性");
	set("age",48);
	set("str",21);
	set("cor",24);
	set("cps",27);
	set("int",30);
	set("per",28);
	set("con",30);
	set("kar",30);
	set("spi",30);

	set("max_force",2000);
	set("force",3000);
	set("force_factor",3);
	set("max_atman",1500);
	set("atman",2000);
	set("max_mana",2000);
	set("mana",4000);
	set("long",
	"絕塵子本爲釋家人，後得奇人指點，得悟道家真諦，佛道雙修，\n"
	"皆入化境。後訪遍名山大川，自號絕塵，創此絕塵一派。\n" );
	
	create_family("絕塵派",1,"祖師");
	set("combat_exp",2000000);
	set("score",200000);
	set("chat_chance_combat",40);
	set("chat_msg_combat", ({
		(:cast_spell, "dun" :),
		(:cast_spell, "saveme" :),
		"絕塵子道：你爲何無故滋事，誤我清修！\n",
"絕塵子道：貧道向以遁世爲樂，你何苦如此相逼？\n",

	}) ) ;
	
	set_skill("force",120);
	set_skill("dodge",100);
	set_skill("parry",120);
	set_skill("unarmed",80);
	set_skill("sword",100);
	set_skill("staff",100);
	set_skill("literate",120);
	set_skill("tao-mystery",120);
	set_skill("perception",100);
	set_skill("magic",150);
	set_skill("spells",150);

	set_skill("juechen-force",120);
	set_skill("magic-array",120);
	set_skill("jingang-staff",100);
		
	map_skill("staff","jingang-staff");
	map_skill("spells","magic-array");
	map_skill("force","juechen-force");

        set("inquiry", ([
                "絕塵派" : "絕塵派是我所創，你有何指教？",
                "拜師"   : "入我派者，需有慧根。",
                "name": "我便是絕塵子。",
              ]) );
                setup();
                carry_object(__DIR__"jingang_staff")->wield();
                carry_object(__DIR__"hat")->wear();
      }

void attempt_apprentice(object ob)
 {

        if((string)ob->query("title")!="普通百姓")
         {
            command("chat "+ob->query("title")+ob->query("nickname")+
            ob->query("name")+"要叛師！！！");
            command("grin");
            kill_ob(ob);
            return;
         }

        if( ((int)ob->query("spi") < 24))
          {     command("say 入我派者，需有慧根。" +
              RANK_D->query_respect(ob) + "的資質不宜！");
               return; }

	if ( ob->query("combat_exp") < 100000 ) {
		command("say "+RANK_D->query_respect(ob) + "似乎尚缺江湖歷練，不宜投入絕塵門下。" );
		return ;
	} 

        command("smile");
        command("say 很好" + RANK_D->query_respect(ob) +
        "多加努力他日必定有成。\n");
        command("recruit " + ob->query("id") );}

void recruit_apprentice(object ob)
         {
                if( ::recruit_apprentice(ob) )
                ob->set("class", "taoist");
        }




