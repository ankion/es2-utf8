// monk_guard.c

inherit NPC;

void create()
{
	set_name("護寺武僧", ({ "monk guard", "guard" }) );
	set("gender", "男性" );
	set("age", 25);
	set("str", 30);
	set("cor", 20);
	set("cps", 22);
	set("int", 16);
	set("per", 20);
	set("spi", 22);
	set("kar", 22);
	set("con", 24);
	set("long", @LONG
    知客僧佇立在佛像前，那虛閉的雙眼中似乎透出一道仁慈而有力的
光芒。
LONG
);
	set("attitude", "heroism");
	set("inquiry", ([
		"山煙寺": "這裏就是山煙寺，施主有何貴幹?",
	]) );

        set("atman", 300);
        set("max_atman", 300);

        set("force", 300);
        set("max_force", 300);
        set("force_factor", 2);

        set("mana", 100);
        set("max_mana", 100);

        set("combat_exp", 6000);

        set_skill("staff", 50);
        set_skill("unarmed", 100);
        set_skill("force", 40);
        set_skill("dodge", 40);
        set_skill("literate", 10);
        set_skill("chanting", 30);
        set_skill("parry", 50);

	setup();

	carry_object("/u/cloud/obj/npc/monk/stick")->wield();
        carry_object("/u/cloud/obj/npc/monk/jiasha")->wear();
}

int accept_fight(object me)
{
        if( (string)me->query("class")=="bonze" )
                command("say 你身爲佛家弟子，竟敢違反清規！");
        else
                command("say 佛門聖地也是可隨意騷擾的麼！");
	return 1;
}

