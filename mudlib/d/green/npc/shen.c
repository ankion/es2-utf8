inherit NPC;
 
void give_jade();
void sell_drug();
 
void create()
{
        seteuid(getuid());
        set_name("沈萬年",({"shen wen-nien","shen"}));
        set("title","沈記商行掌櫃");
        set("gender", "男性" );
        set("age",45);
        set("combat_exp",30);
        set("attitude", "friendly" );
        set_temp("apply/dodge",5);
        set_temp("apply/attack",3);
        set("inquiry", ([
            "玉佩" : (: give_jade :),
            "蒙汗藥" : (: sell_drug :),
        ]) );
        setup();
        carry_object("/obj/cloth")->wear();
        add_money("silver",1);
}
 
void init()
{
        add_action("list_item","list");
        add_action("buy_item","buy");
}
 
int list_item()
{
        write("你看到:\n");
        write("櫃子上一堆冥紙和香燭等, 標價 10 文錢. 牆上掛著幾把竹掃帚,\n");
        write("每把 50 文錢. 櫃檯上擺\著一塊木牌, 上面寫著:\n");
        write("棺材: 時價. 沒看到的東西問一下掌櫃的, 我們應該都有.\n");
        return 1;
}
 
int buy_item()
{
        command("shake");
        command("say 我不賣東西給陌生人!");
        return 1;
}
 
void give_jade()
{
        object ob;
        if (this_player()->query_temp("give_alcohol")) {
               if(this_player()->query_temp("had_jade")) {
                    command("say 你真貪心耶... ");
                    return;
                }
                ob = new("/d/green/obj/jade");
		if (ob->violate_unique()) {
		command("hmm");
		command("say 這樣東西... 剛剛有人來要過了.");
		command("shrug");
		destruct(ob);
		return;
		}
                ob->move(this_object());
                command("give jade to "
                   +(string)this_player()->query("id"));
                this_player()->set_temp("had_jade",1);
           }
           else command("?");
        return;
}
 
void sell_drug()
{
        if (this_player()->query_temp("know_drug")) {
            command("whisper "+(string)this_player()->query("id")+
            " 一份只要 10 兩銀子, 保證有效喔.\n");
            command("grin");
            this_player()->set_temp("can_buy_drug",1);
        }
        else command("?");
        return;
}
 
int accept_object(object who, object ob)
{
        object drug;
        if(who->query_temp("can_buy_drug") ) {
                if( ob->value() >= 1000 ) {
		drug = new("/obj/slumber_drug");
                drug->move(this_player());
                tell_room(environment(this_player()),
                "老闆鬼鬼祟祟地塞了一樣東西給"
                    +(string)this_player()->name()+"。\n",
                    ({this_object(), this_player()}) );
                tell_object(this_player(),"老闆塞了一包蒙汗藥給你。\n");
                }
                else {
                command("shake");
                command("say 想騙我啊?\n");
                this_player()->delete_temp("give_alcohol");
                this_player()->delete_temp("know_drug");
                }
        } else {
				if(!ob->value()) { return 0;} else {
                command("say 我不知道你給我錢幹嘛, 不過謝啦!");
                command("grin");
                }
        }
        return 1;
}
 
