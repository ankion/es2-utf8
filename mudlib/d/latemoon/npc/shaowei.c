inherit NPC;
#include <ansi.h>
 
string *make_msg = ({
    HIY "筱薇微笑的看著你說：你要作竹蜻蜓呀!\n\n" NOR,
    HIY "筱薇將你給她的竹子仔細的看了一下。說道：不錯是根玉竹! \n\n" NOR,
    HIY "筱薇將竹子周圍的葉子弄掉，靈巧的削鑿著。\n\n" NOR,
    HIY "經過不久，筱薇把竹蜻蜓做好了。\n\n" NOR,
    HIY "筱薇將做好的竹蜻蜓遞給你，微笑說道：嗯! 做好了! \n\n" NOR,
});

void create()
{
        set_name("藍筱薇", ({ "shao-wei","shaowei","wei"  }) );
        set("gender", "女性" );
        set("age",18);
        set("long", @TEXT
她長得十分漂亮！讓你忍不住多瞧她幾眼，從她身上
你聞到淡淡的香氣。她很有禮貌的向你點頭，優雅的
動作，輕盈的步伐，好美哦!
她是晚月莊主藍止萍的養女。
TEXT
);
       set("class", "dancer");
       set("combat_exp", 200000);
        set_skill("unarmed",70);
        set_skill("dodge", 80);
        set_skill("force",70);
        set_skill("sword",70);
        set_skill("stormdance", 50);
        map_skill("dodge","stormdance");
        set("force", 3000);
        set("max_force", 600);

        set("force_factor", 10);
        set("inquiry", ([
        "舞" : "我舞跳的不好!我比較喜歡靜態的活動。\n",
        "竹蜻蜓" : "咦..!你也喜歡玩啊! 我會做哦! \n" +
                   "不過我需要一根竹子! 你找來我幫你做! \n",
        "芳綾" : "聽說她貪玩被關在禁閉室。她最愛玩竹蜻蜓了! \n",
        ]));
        create_family("晚月莊",2,"大弟子");

        setup();
        carry_object("/d/latemoon/obj/clasp")->wear();
        carry_object("/d/latemoon/obj/deer_boot")->wear();
        carry_object("/d/latemoon/obj/skirt2")->wear();
        carry_object("/d/latemoon/obj/bamboo_sword")->wield();

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
                  say( "筱薇對你微笑，和善的對你點點頭。\n");
                        break;
                case 1:
                  say( "筱薇對你微笑，以纖細輕柔的聲音 \n 說道：這位" +
RANK_D->query_respect(ob)
                   + "，你好！歡迎來到晚月莊。\n");
        }
}

int accept_object(object who, object ob)
{
     string objname;
     objname = (string)ob->name();

        if ( objname != "竹子")  {
           command("smile");
            say ( HIY "這要送給我啊?! 怎麼好意思!謝謝你。\n" NOR);
           command("blush");
             return 1;
            }
        if( !who->query_temp("moon/竹子") )  {
          call_out( "make_stage", 2, who, 0 );

            who->set_temp("moon/竹子", 1);
         } else {
             say (HIY "我已經幫你做一個竹蜻蜓了呀! \n" NOR);
             return 1;
          }
          return 1;
}
void make_stage(object who, int stage)
{
     object obj;
     tell_object(who, make_msg[stage]);
     if( ++stage < sizeof(make_msg) ) {
         call_out( "make_stage", 2, who, stage );
         return;
     } else
       obj = new("/d/latemoon/obj/dragonfly");
       obj->move(who);
    return;
}
