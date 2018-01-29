// monk_waiter.c

inherit NPC;

void create()
{
	set_name("知客僧", ({ "monk waiter", "waiter" }) );
	set("gender", "男性" );
	set("age", 46);
	set("str", 29);
	set("cor", 26);
	set("cps", 29);
	set("int", 22);
	set("per", 18);
	set("spi", 23);
	set("kar", 25);
	set("con", 27);
	set("long", @LONG
    知客僧佇立在佛像前，那虛閉的雙眼中似乎透出一道仁慈而有力的
光芒。
LONG
);
	set("attitude", "friendly");
	set("chat_chance_combat", 15);
	set("chat_msg_combat", ({
		"知客僧說道：佛門清淨，施主還是放下屠刀吧！\n",
		"知客僧說道：趁住持不在此，施主還是速速離開的好！\n",
		"知客僧招數出到一半又收回，似乎有些疑慮。\n",
		"知客僧說道：我佛慈悲，願施主手下留情。\n"
	}) );
	set("inquiry", ([
		"山煙寺": "這裏就是山煙寺，施主有何貴幹?",
	]) );

        set("atman", 1000);
        set("max_atman", 1000);

        set("force", 800);
        set("max_force", 800);
        set("force_factor", 3);

        set("mana", 200);
        set("max_mana", 200);

        set("combat_exp", 10000);
        set("score", 1000);

        set_skill("staff", 60);
        set_skill("unarmed", 80);
        set_skill("force", 60);
        set_skill("dodge", 40);
        set_skill("literate", 50);
        set_skill("chanting", 30);
        set_skill("parry", 60);
        set_skill("magic", 30);

        set_skill("cloudstaff", 20);
        set_skill("lotusforce", 20);
        set_skill("buddhism", 20);
        set_skill("essencemagic", 20);

        map_skill("staff", "cloudstaff");
        map_skill("parry", "cloudstaff");
        map_skill("force", "lotusforce");
        map_skill("magic", "essencemagic");

	setup();

//	carry_object("/u/cloud/obj/npc/monk/stick")->wield();
        carry_object("/u/cloud/obj/npc/monk/jiasha")->wear();
}

int accept_fight(object me)
{
        if( (string)me->query("class")=="bonze" )
                command("say 阿彌陀佛！出家人戒逞強惡鬥！貧僧不敢違反清規。");
        else
                command("say 施主既然身負絕藝，貧僧佩服便是，也不必較量了。");
	return 0;
}

