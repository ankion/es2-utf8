// maid.c

inherit NPC;

void create()
{
	set_name("丫鬟", ({ "maid" }) );
	set("long", "一個服侍有錢人家小姐的丫鬟，正無聊地玩弄著衣角。\n");
	set("age", 17);
	set("gender", "女性");
	set("attitude", "peaceful");
	set("combat_exp", 10);
	set("env/wimpy", 100);
	set("inquiry", ([
		"here": "這裏啊？這裏就是喬陰縣有名的翠柳湖啊！",
	]) );
	setup();
	carry_object("/obj/cloth")->wear();
}

