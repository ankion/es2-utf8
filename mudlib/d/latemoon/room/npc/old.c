
// old.c

inherit NPC;

void create()
{
	set_name("無名老婦", ({ "old" }) );
      set("title", "看管人" );
	set("long", "這個老婦人不知姓甚名誰, 她在晚月很久了, 一直看管\n書房, 連莊主都對她很尊敬。\n");
      set("gender", "女性" );
	set("age", 62);
	set("attitude", "peaceful");
	set("str", 20);
	set("cor", 26);
	set("cps", 26);
	set("per", 29);
	set("inquiry", ([
		"here": "這裏是書房，有些鞭法教材存放在這兒。",
		"trouble":
			"實不相瞞，這殺手是我的私生女，但已誤入歧途 ...\n我一直捨不得親手殺了她，你若能幫忙我會非常感謝。 \n只是要以令牌爲證，唉 ...",
		"令牌" : "就在我兒身上 ...你拿到了就給我。",
	]) );
      set("class", "dancer");
      set("combat_exp", 500000);
      set("score", 1000);
      set_skill("dodge", 70);
      set_skill("stormdance", 70);
      set_skill("tenderzhi", 70);
      set_skill("snowwhip", 60); 
      map_skill("dodge","stormdance");
      map_skill("whip","snowwhip"); 
      map_skill("unarmed","tenderzhi");
      set("force", 1000);
      set("max_force", 800);
      set("force_factor", 10);
      create_family("晚月莊", 1, "前輩");

      setup();
      carry_object("/d/latemoon/obj/deer_boot")->wear();
      carry_object("/d/latemoon/obj/blue_dress")->wear();
	carry_object("/u/cloud/obj/npc/lm_guard/whip")->wield();
}

int accept_object(object me, object ob)
{
        object book;	
        int iNeiLiTrans;
	if( !ob->id("###token###") ) return 0;
	command("sigh");
      if( (int)me->query( "max_force" ) < 160 
               && ((string)me->query("family/family_name")=="晚月莊") )
      {
         command("say 作爲感謝，我傳你一些內力。");
         message_vision( "無名老婦手抵在$N的後心，頭上冒出絲絲白氣。 \n", me );
         message( "vision", "你感覺到一股熱氣傳了過來。 \n", me );
         iNeiLiTrans = 160-(int)me->query( "max_force" );
         if( iNeiLiTrans>50 ) 
             iNeiLiTrans = random( 50 );
         else
             iNeiLiTrans = random( iNeiLiTrans ); 
	 if( iNeiLiTrans > 20 ) iNeiLiTrans = 20;
	 iNeiLiTrans = iNeiLiTrans*(int)me->query_kar()/30; 
         me->set("max_force", (int)me->query("max_force")+iNeiLiTrans );
         me->set("force", 0);
      }
      else
      {
         command("say 作爲感謝，我給你一本寒雪鞭法密笈。");
         book = new(__DIR__"obj/whip_book");
         book->move(me);	
        //delete("inquiry/trouble");
	//delete("inquiry/令牌");
      }
	return 1;	
}
