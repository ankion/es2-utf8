// shiao.c

inherit NPC;

void create()
{
	set_name("赫造基", ({ "adviser" }));
	set("title","軍師");
	set("gender", "男性");
	set("age", 44);
	set("long",
        	"道光滿面，□智不言而現，氣象萬千，顯然是茅山術高手中的高\n"
        	"手，經綸羽扇，和大將軍正是絕配。\n");

	set("attitude", "peaceful");

	set("str", 20);
	set("int", 30);

	set("combat_exp", 300000);
        
        set("inquiry", ([
        	"兵器庫" : "先看看你的誠意再說羅。\n",
        ]) );
        
        set("chat_chance_combat", 80);
	set("chat_msg_combat", ({
	        (: cast_spell, "drainerbolt" :),
	        (: cast_spell, "netherbolt" :),
	        (: cast_spell, "feeblebolt" :),
	        (: cast_spell, "invocation" :),
	}) );        
	
	set("force", 600);
	set("max_force", 600);
	set("force_factor", 5);
        
        set("atman", 600);
        set("max_atman", 600);
        
        set("mana", 2000);
        set("max_mana", 1200);
	set("mana_factor", 5);
	
        set_skill("literate", 60);
        set_skill("magic", 60);
        set_skill("force", 25);
        set_skill("spells", 80);
        set_skill("unarmed", 30);
        set_skill("sword", 40);
        set_skill("parry", 35);
        set_skill("dodge", 40);
        
        set_skill("taoism", 60);
        set_skill("necromancy", 70);
        set_skill("gouyee", 50);
        
        map_skill("magic", "taoism");
        map_skill("spells", "necromancy");
        map_skill("force", "gouyee");
        
        set_temp("apply/dodge",15);
        set_temp("apply/armor",15);
         
	setup();

	carry_object(__DIR__"obj/fan_sword")->wield();
	carry_object(__DIR__"obj/hat")->wear();
}

int accept_object(object who,object ob)
{
        if ( !ob->value() ) {
        	command("say ㄟ....Ｔhank Ｙou!!!");
                command("grin");
              //  call_out( (: destruct :), 1, ob);
                return 1;
	}
                                                                                                                                                                
	if( !who->query_temp("軍營/swear") ) {
		if( ob->value() >= 800 ) {
            	   command("say 好極了，我就告訴你一項祕密吧。");
            	   command("say 在那片光滑的山壁前發誓(swear) 我愛.....。");
                   command("say 或許\你可以發現奇特的事喔。");
                   who->set_temp("軍營/swear", 1);
		   return 1;
		} else {
		   command("say 錢太少了吧！沒收。");
		   return 1;
		}
	} else 
		command("say 即然你那麼有心，那我就勉強收起來了。");
	
	return 1;
}
