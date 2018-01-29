inherit NPC;
inherit F_VENDOR;

void create()
{
      object ob;

        set_name("顏慧如", ({ "Huei Ru","huei","huei ru" }) );
        set("gender", "女性" );
        set("age", 27);
        set("long",
"她是一位美女，真是紅顏似玉，綠鬢如雲，明麗的眼睛，\n"
"潔白的牙齒。容色俊俏，風度飄逸，令人心動。\n");
        set("combat_exp", 70000);
        set("force",1000);
        set("max_force", 1000);
        set_skill("force",10);
        set_skill("dodge", 30);
         set_skill("stormdance", 30);
        map_skill("dodge","stormdance");
        set_skill("unarmed", 10);
        set("inquiry", ([
            "buy":          (: this_object(), "ask_buy" :)
        ]) );
        set("chat_chance", 7);
        set("chat_msg", ({
"顏慧如說道：小本生意！  物美價廉，歡迎訂購(order)。\n",
"顏慧如梳了梳頭髮。\n",
"顏慧如眼睛眨呀眨看著你。\n"
        }) );
        create_family("晚月莊",2,"弟子");
        setup();
        ob = carry_object("/obj/example/dagger");
}

void init()
{
        object ob;

        ::init();
        add_action("do_list","list");
        add_action("do_buy","order");
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}
void greeting(object ob)
{
        if( !ob || !present(ob, environment(this_object())) ) return;
         say( "顏慧如說道：這位" + RANK_D->query_respect(ob)
             + "，要不要買些東西呀。\n");
}

int accept_object(object who, object ob)
{
        int val;

        val = ob->value();
        if( !val )
                return notify_fail("姑娘我不要以物易物。\n");
        else if( val > 100 ) {
                if( (who->query("bellicosity") > 0)
                &&      (random(val/10) > (int)who->query("kar")) )
                        who->add("bellicosity", - 
(random((int)who->query("kar")) + val/1000) );
        }
        say( "顏慧如說道：多謝這位" + RANK_D->query_respect(who)
                + "，神明一定會保佑你的。\n");

        return 1;
}

int ask_buy(object who)
{
        write("小本生意，價錢決對公道。\n"
              "詳列細目 :  list \n"
              "訂購物品 :  order [<物品名稱>]  \n");
     return 1;
}

int do_list(string arg)
{
      write( "我賣有以下物品 : \n"
          "\n 單位：銀子 (silver) \n \n"
             "No.    價格.      名稱 \n"
             "1. [   五兩   ]  花裙 (skirt) \n"
             "2. [   十兩   ]  女兒紅 (wine) \n"
             "3. [ 二十兩   ]  鹿皮小靴 (boots) \n"
             "4. [ 五十兩   ]  仙豆  (sen-bean) \n"
             "5. [ 一百兩   ]  大還丹 (heal pill) \n \n"
    "如果你不說訂購什麼!那我就賣你女兒紅喔! \n \n"
            );
      return 1;
}

int do_buy(string arg)
{
       string name,unit,objname;
       int amount,bv;
       object obj, player,from_ob,who_ob;

       amount = 10;

       player = this_player();
    if(!arg )
          return notify_fail("你要買什麼東東呀?說清楚嘛! \n");
       else {
      switch ( arg )  {
              case "wine" : obj= new("/d/latemoon/sell/wine");
                            amount = 10;
                            break;
              case "skirt" : obj= new("/d/latemoon/sell/skirt");
                             amount = 5;
                             break;
              case "boots" : obj= new("/d/latemoon/sell/boots");
                             amount = 20;
                             break;
              case "sen-bean" : obj= new("/d/latemoon/sell/bean");
                                amount = 50;
                                break;
              case "heal pill" : obj= new("/d/latemoon/sell/pill");
                                 amount = 100;
                                 break;
              default : return notify_fail("你要買什麼?\n");
                        break;
      }
       from_ob = present("silver_money",this_player());
       if( !from_ob )    return notify_fail("你身上沒有銀兩耶。\n");
       if( (int)from_ob->query_amount() < amount )
       return notify_fail("你身上沒有那麼多銀兩耶！\n");
          from_ob->add_amount(-amount);
          obj->move(player);
       }
       name = (string)this_player()->query("name");
       unit = (string)obj->query("unit");
       objname = (string)obj->query("name");

       tell_room(environment(this_object()),"顏慧如給"+name
              +"一"+unit+objname+"\n");
             say ("顏慧如說道：謝謝你!下次再來! \n");

       return 1;
}
void die()
{
        object *inv;
        int i;
        revive();
        command("grin");
        command("shake");
        command("say 你這樣是殺不死我的!! ");
        command("say 嘻..");
        inv = all_inventory(environment(this_object()));
        i = sizeof(inv);
        while (i--)
            if (living(inv[i])) inv[i]->remove_all_killer();
        return;
}
