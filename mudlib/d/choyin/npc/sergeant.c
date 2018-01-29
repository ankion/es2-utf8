// sergeant.c

inherit NPC;

int chest_found = 0;

void create()
{
	set_name("武官", ({ "sergeant" }) );
	set("long",
		"一位相貌威武的武官，獨自一個人站在這裏發呆，似乎正有什麼\n"
		"事困擾著他。\n" );
	set("age", 29);
	set("combat_exp", 250000);
	set("env/wimpy", 10);
	set("str", 28);
	set("cor", 28);
	set("cps", 28);
	set("pursuer", 1);
	set("inquiry", ([
		"name" : "在下姓陳，名顯祖，閣下是？",
		"here" : "真是不巧，我也是外地來的，對這個地方並不熟悉。",
		"rumors" : "在下失落了一件重要物事，是裝在一個桃木箱子裏，不知你有沒有看見？",
		"箱子" : "對，是桃木做成的箱子。",
		"桃木箱子" : "如果你見著了，麻煩送還給我，在下定當重重報答。",
		"陳顯祖" : "不敢，正是在下，不知閣下有何指教？"
	]) );
	set_skill("dodge", 70);
	set_skill("unarmed", 60);
	set_skill("parry", 70);
	set_skill("sword", 75);

	set_temp("apply/attack", 60);
	set_temp("apply/defense", 60);
	set_temp("apply/damage", 30);

	setup();
	carry_object("/obj/cloth")->wear();
	carry_object("/obj/longsword")->wield();
}

int accept_object(object me, object ob)
{
	object book;

	if( !chest_found && ob->id("peach chest") ) {
		chest_found = 1;
		command("say 太好了！就是這個箱子！");
		command("say 在下出門在外，沒有攜帶太多銀兩 ... ");
		command("say 如果您不嫌棄的話，這本古書便請笑納。");
		book = new(__DIR__"obj/magic_book");
		book->move(this_object());
		command("give book to " + me->query("id"));
		delete("inquiry/rumors");
		delete("inquiry/箱子");
		delete("inquiry/桃木箱子");
		return 1;
	}
	return 0;
}
