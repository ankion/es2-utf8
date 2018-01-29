inherit NPC;
#include <ansi.h>
 

void create()
{
        set_name("昭蓉", ({ "zauron","zau","ron" }) );
        set("gender", "女性" );
        set("age",18);
        set("long", @TEXT
她長得十分漂亮！讓你忍不住多瞧她幾眼，從她身上
你聞到淡淡的香氣。她很有禮貌的向你點頭，優雅的
動作，輕盈的步伐，好美哦!
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
        "芳綾" : "聽說她貪玩被關在禁閉室。她最愛玩竹蜻蜓了! \n",
        ]));
        create_family("晚月莊",2,"弟子");

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
                  say( "昭蓉對你微笑，和善的對你點點頭。\n");
                        break;
                case 1:
                  say( "昭蓉對你微笑，以纖細輕柔的聲音 \n 說道：這位" +
RANK_D->query_respect(ob)
                   + "，你好！歡迎來到晚月莊。\n");
        }
}

