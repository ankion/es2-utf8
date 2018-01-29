// boss.c

inherit NPC;

void create()
{
	set_name("湯掌櫃", ({ "boss tang", "tang", "boss" }) );
	set("long",
		"湯掌櫃是這家大酒樓的主人，別看他只是一個小小的酒樓老闆，喬陰\n"
		"縣境內除了知縣老爺以外，恐怕就屬他最財大勢大。\n" );
	set("age", 46);
	set("attitude", "peaceful");
	set("combat_exp", 1000);
	set("inquiry", ([
		"name": "在下姓湯單名一個業字。\n",
		"here": "此處便是福林酒樓，客倌如要點菜，吩咐店裏的小二一聲便可。\n",
		"湯業": "不敢，在下便是湯業，不知客倌有何吩咐？\n",
		"福林酒樓": "這裏就是，客倌是第一次來嗎？\n"
	]) );
	setup();
	add_money("silver", 15);
	carry_object("/obj/cloth")->wear();
}

