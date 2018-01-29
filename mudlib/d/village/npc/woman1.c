// 7-19-96 /d/village/npc/woman1.c

inherit NPC;

void wield_weapon();
void converse_one();

void create()
{
//	seteuid(geteuid());
        set_name("農婦",({"woman"}));
        set("gender","女性");
        set("age",30);
       
	set("chat_chance",20);
	set("chat_msg", ({
		"農婦道：我可憐的兒啊，你到那裏去了？\n",
		"農婦道：你有見到我的兒嗎？，他頭上梳着兩個小抓揪，只有七歲。\n",
	"農婦嘆道：兒啊！\n",
	}) ); 
	set("inquiry",([
		"兒":"我的兒前兩天不見了，我和他爹到處找都找不到。聽說黑松山總抓小孩子。\n",
	]) );
	
	set("combat_exp",(20+random(40)));
        set_temp("apply/dodge",(10+random(5)));
        add_money("coin",90);
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
        (: wield_weapon :),
        (: converse_one :) }) );
        
	setup();
        carry_object("/obj/cloth")->wear();
        //carry_object(__DIR__"obj/ricewine");
        carry_object(__DIR__"obj/knife");
}

void wield_weapon()
{
    if (!query_temp("weapon")) {
        command("say 沒見識過我的菜刀神功\是吧, 接招!");
        command("wield knife");
        set("chat_chance_combat", 10);
    }
        return;
}

void converse_one()
{
    object ob;
    ob = this_player();
    if ((int)ob->query("age") < (int)query("age")) {
        command("say 唉，我那可憐的兒啊，年齡比你還小。!");
        command("slap "+(string)ob->query("id"));
    }
    else
        command("say 以大欺小啊你...");
    return;
}

