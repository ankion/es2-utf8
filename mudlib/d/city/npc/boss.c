// boss.c

inherit NPC;

void create()
{
        set_name("錢掌櫃", ({ "boss qian", "qian", "boss" }) );
	set("nickname", "錢千萬");
        set("long",
"錢掌櫃長得如一個大面團般，白白胖胖的，雖說早已步入知天命\n"
"的年齡，可保養得很好。一雙小眼睛如倆棗核嵌在臉上，不時滴\n"
"溜溜地亂轉。他開的「太白酒樓」可是京城最大的。\n"
	);

        set("age", 53);
        set("attitude", "peaceful");
        set("combat_exp", 1000);
        set("inquiry", ([
                "name": "在下姓錢，因少有資產，別人叫我錢千萬。\n",
                "太白酒樓": "這裏就是，客倌是第一次來嗎？\n",
		"皇上": "小聲點。偷偷地告述你，我真見過皇上的。\n",
		"作官": "瞧見沒有，上面的人才是你應去打聽的。\n"
        ]) );
        setup();
        add_money("gold", 1);
        carry_object("/obj/cloth")->wear();
}


void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
	        }
}

void greeting (object ob)
{
	if( !ob || environment(ob) != environment() ) 
		return;

	if (!ob->query("rank")) 
		say ("錢千萬皺了皺眉，說:這裏是可不是爲你們開的，吃完了快走。\n");
	    else 
		say ("錢千萬堆滿了笑臉引上去：哪陣香風把你迎來了。\n");
}

