inherit NPC;
 
void create()
{
        object ob;

        set_name("藍小蝶", ({ "shao-de" }) );
        set("gender", "女性" );
        set("age",18);
        set("long", @TEXT
她長得十分漂亮！讓你忍不住多瞧她幾眼，從她身上
你聞到淡淡的香氣。她很有禮貌的向你點頭，優雅的
動作，輕盈的步伐，好美哦!
她是晚月莊主藍止萍的養女，平常莊內的接待是看她。
TEXT
);
       set("class", "dancer");
       set("combat_exp", 60000);
       set("potential", 200);
        set("kee",350);
        set("san",100);
        set_skill("unarmed",60);
        set_skill("dodge", 50);
        set_skill("force",50);
       set("force", 2000);
       set("max_force", 2000);
       set("force_factor",2);
       set_temp("apply/armor", 50);
       create_family("晚月莊",3,"大弟子");

        setup();
        ob = carry_object(__DIR__"obj/needle");
        ob->set_amount(30);
        carry_object(__DIR__"obj/deer_boot")->wear();
        carry_object(__DIR__"obj/skirt3")->wear();
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
        if( !ob || !present(ob, environment(this_object())) ) return;
        switch( random(2) ) {
                case 0:
                  say( "小蝶對你微笑，和善的對你說：\n  這位" + 
RANK_D->query_respect(ob)
                   + "，你好！歡迎來到晚月莊。請坐！\n");
                        break;
                case 1:
                  say( "小蝶對你微笑，纖細的雙手捧著茶，\n 說道：這位" +
RANK_D->query_respect(ob)
                   + "，你好！歡迎來到晚月莊。請用茶！\n");
        }
}
