//traveller.c
inherit NPC;

void create()
{
        set_name("遊客", ({ "visitor"}));
        if(random(10)<7)
            set("gender", "男性" );
        else
            set("gender", "女性" );
        set("age", 15+random(50));
        set("long",
	"這是一位來喬陰縣遊玩的遊客。\n");

	set("env/wimpy",20);
	set("max_kee",1000);
        set("combat_exp", 5000);
        set("attitude", "friendly");
        set_skill("dodge", 90);
        set_skill("unarmed", 76);
	set("str",20);
	set("cor",50);
	set_temp("apply/armor",30);
	
	set ("inquiry", ([
		"here": "我遊歷過大半個中國，小小的喬陰縣對我能有什麼祕密？\n",
		"忘憂草": "這個。。好象是給獅子銜去了。\n",
		]) );

        setup();
        carry_object("/obj/cloth")->wear();
        add_money("silver", 5);
}



