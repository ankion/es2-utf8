// girl.c

inherit NPC;

string ask_youngman();

void create()
{
	set_name("官家小姐", ({ "girl" }) );
	set("long", "一個看起來像是有錢人家的女子，正在這裏遊湖。\n");
	set("age", 23);
	set("gender", "女性");
	set("attitude", "peaceful");
	set("combat_exp", 10);
	set("env/wimpy", 100);
	set("inquiry", ([
		"name": "我 ... ？ 你們外地人都做興這麼問陌生姑娘的閨名嗎？",
		"here": "這裏啊？這裏就是喬陰縣有名的翠柳湖啊！",
		"閨名": "真是沒有禮貌的傢伙，我纔不告訴你！",
		"遊晉" : (: ask_youngman :), 
	]) );
	setup();
	carry_object(__DIR__"obj/lady_dress")->wear();
	carry_object(__DIR__"obj/silver_clasp")->wear();
}

string ask_youngman()
{
	object bag, me;

//	if( !me = query_temp("last_asker") ) return "您說的是 ... 遊尚書遊大人府上的遊 ... 遊相公嗎？\n";

	bag = new(__DIR__"obj/silk_bag");
	bag->move(this_player());
        return "小女子有一事相求 ... 請您將這個交給遊 ... 遊公子。\n";
        delete("inquiry/遊晉");
}

