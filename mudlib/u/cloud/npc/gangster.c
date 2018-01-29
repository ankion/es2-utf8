// gangster.c

inherit NPC;

string kill_passenger(object who);

void create()
{
        set_name("臥龍崗強盜", ({ "gangster" }) );
        set("gender", "男性" );
        set("age", 27);
        set("str", 27);
        set("int", 12);
        set("per", 10);
        set("long", @LONG
這強盜滿臉傷疤，虎背熊腰，一臉兇狠而霸道的樣子。
LONG
);
        set("attitude", "heroism");

        set("combat_exp", 10000);

//        set("chat_chance", 1);
//        set("chat_msg", ({
//             "強盜喝道：呔！此山是我開，
//此樹乃我栽。要想從此過，留下買路財！\n",
//              "強盜將你上上下下打量了一番，
//說道：識相的放下十兩買路錢走你的路。\n",
//        }) );

        set("inquiry", ([
                "買路錢": 
"看你也不象有錢的樣子，大爺我只要十兩金子意思一下。\n",
        ]) );

//        set("chat_chance_combat", 1);
//        set("chat_msg_combat", ({
//              "強盜顯是以劫爲生，刀刀衝要害而來。\n",
//              "強盜高喊：叫你人財兩空。\n",
//        }) );

        set_skill("unarmed", 100);
        set_skill("blade", 40);
        set_skill("dodge", 40);
        set_skill("parry", 50);

        set("score", 100);

        setup();

        add_money("gold", 1); 
        carry_object("/u/cloud/obj/npc/gangster/blade")->wield();
        carry_object("/obj/dust");
        carry_object("/obj/example/dart")->wield();
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

void greeting(object ob)
{
        if( !ob->query("marks/強盜") ) {
                set("chat_chance", 1);
                set("chat_msg", ({
                        
"強盜喝道：呔！此山是我開，此樹乃我栽。要想從此過，留下 
買路財！\n",
                        
"強盜將你上上下下打量了一番，說道：識相的放下十兩買路錢 
走你的路。\n",
                }) );
                kill_passenger(ob);
        }
}

int accept_object(object who, object ob)
{
        if( !who->query("marks/強盜") ) {
                if( ob->value() >= 100000 ) {
                        say("強盜接過錢，眼睛瞪得大大的，點了點頭，說道：
大爺今天做個善人，放你條生路。還不快滾！\n");
                        who->set("marks/強盜", 1);
                        return 1;
                } else {
                        say("強盜往地上吐了口唾沫，目露兇光，說道：
不給你點顏色你是不知道大爺的厲害！\n");
                        kill_passenger(who);
                        return 0;
                }
        } else
                
say("強盜眼中放出異樣的光彩，忙不迭的笑道：算你識相，以後我不會
難爲你的。\n");
        return 1;
}

string kill_passenger(object who)
{
//        set("pursuer", 1);
        set("attitude", "aggressive");
        set("chat_chance_combat", 15);
        set("chat_msg_combat", ({
                "強盜顯是以劫爲生，刀刀衝要害而來。\n",
                "強盜高喊：叫你人財兩空。\n",
        }) );
        kill_ob(who);
        return 0;
}

int accept_fight(object me)
{
        command("say 竟敢太歲爺頭上動土？納命來！");
        command("grin");
        kill_passenger(me);
        return 1;
}

 
