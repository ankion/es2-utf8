// youngman.c

inherit NPC;

void create()
{
	set_name("貴公子", ({ "youngman" }) );
	set("long", "一個相貌俊美的年輕貴公子正優雅地欣賞著窗外的景物。\n");
	set("age", 22);
	set("attitude", "peaceful");
	set("combat_exp", 2500);
	set("env/wimpy", 50);
	set("str", 20);
	set("cor", 26);
	set("cps", 26);
	set("per", 29);
	set("inquiry", ([
		"name": "在下姓遊，單名一個晉字，不知閣下如何稱呼？",
		"here": "這裏是喬陰縣城，您是外地來的吧？",
		"trouble": ({
			(: command, "hmm" :),
			"實不相瞞，在下仰慕前面曲橋上賞蓮的姑娘已久 ...",
			"但是一直不知那位姑娘芳名 ...",
			"唉 ..."
			}),
		"姑娘" : "就是那位綠裙黃衫的姑娘 ...",
	]) );
	set_skill("dodge", 40);
	set_skill("unarmed", 40);
	set_skill("parry", 40);
	set_skill("sword", 40);
	setup();
	carry_object(__DIR__"obj/hat")->wear();
	carry_object("/obj/cloth")->wear();
	carry_object("/obj/longsword")->wield();
}

int accept_object(object me, object ob)
{
	if( !ob->id("###silk bag###") ) return 0;
	message("vision", name() + "一眼瞥見荷包上的鴛鴦圖案，立刻一把搶了過去。\n"
		+ name() + "隨即從懷中掏出一方手帕，上面竟也繡著一幅相同的鴛鴦圖。\n", environment());
	command("say 原來爹爹替我主張的婚事，竟然是 ...");
	command("jump");
	delete("inquiry/trouble");
	return 1;	
}
