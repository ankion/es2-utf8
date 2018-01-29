// butcher.c

inherit NPC;

void create()
{
        set_name("廚子", ({ "cook" }) );
        set("gender", "男性" );
        set("age", 35);
        set("long", "你看到一個小廚子， 正在用碧玉刀剔豬骨。\n");
        set("str", 29);
        set("int", 14);
        set("combat_exp", 2500);
        set("attitude", "heroism");
        set_skill("dagger", 100);
        set_skill("parry", 100);
        set_skill("dodge", 150);
        set("inquiry", ([
                "小娟" : "這要到地牢去找。",
                "淳于" : "這要到地牢去找。",
                "淳于懷太" : "這要到地牢去找。",
                "堡主" :"這要到地牢去找。",
        ]) );

        setup();
        add_money("coin", 500);
        carry_object("/obj/cloth")->wear();
        carry_object(__DIR__"obj/bknife")->wield();
        carry_object(__DIR__"obj/qiwine");
        carry_object(__DIR__"obj/pigmeat");
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
        if( !ob || environment(ob) != environment() ) return;
        switch( random(2) ) {
                case 0:
                 say( "廚子嘟囔着：“真是的，堡主又在地牢裏留漣忘返。”\n");
                    break;
                case 1:
                        say( "廚子道：“去地牢叫堡主上來吃飯。\n");
                        break;
        }
}


