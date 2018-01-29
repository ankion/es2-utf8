// master.c

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("柳淳風", ({ "master swordsman", "swordsman", "master" }) );
        set("nickname", "風雨雙俠");
        set("gender", "男性" );
        set("age", 44);
        set("str", 27);
        set("cor", 30);
        set("cps", 27);
        set("int", 24);

        set("max_force", 1500);
        set("force", 1500);
        set("force_factor", 3);

        set("rank_info/respect", "柳館主");

        set("long",
                
"柳淳風是個相當高大的中年儒生，若不是從他腰間掛著的「玄蘇劍」你\n"
                "大概猜不到眼前這個溫文儒雅的中年人竟是家大武館的館主。\n");

        create_family("封山劍派", 13, "掌門人");

        set("combat_exp", 1000000);
        set("score", 200000);

        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
                (: perform_action, "sword.counterattack" :)
        }) );

        set_skill("unarmed", 40);
        set_skill("parry", 120);
        set_skill("dodge", 80);
        set_skill("sword", 150);
        set_skill("force", 40);
        set_skill("literate", 60);

        set_skill("fonxanforce", 60);
        set_skill("fonxansword", 150);
        set_skill("liuh-ken", 60);
        set_skill("chaos-steps", 100);
        set_skill("spider-array", 85);

        map_skill("unarmed", "liuh-ken");
        map_skill("sword", "fonxansword");
        map_skill("parry", "fonxansword");
        map_skill("dodge", "chaos-steps");

        set("inquiry", ([
                "淳風武館" : 
"淳風武館是先父所創，在下辱承其名，雖忝掌封山門戶，不敢忘了先人遺志。",
                "先人遺志" : 
"先父臨終之時將這武館交到在下手中，需得好好照看。",
                "劉安祿" : "劉兄弟在寒舍管事已經五年了，過去之事不須再提。",
                "name": "你既然知道我是柳□主，怎麼不知道我是柳淳風？",
                "here": "這裏便是淳風武館。",
        ]) );

        setup();
        carry_object(__DIR__"blackthorn")->wield();
        carry_object(__DIR__"silk_cloth")->wear();
}

void attempt_apprentice(object ob)
{
        if( ((int)ob->query_cor() < 20) 
        ||      ((int)ob->query_cps() < 20)) {
                command("say 學劍之人必須膽大心細，依我看" + 
RANK_D->query_respect(ob) + "的資質似乎不宜？");
                return;
        }
        command("smile");
        command("say 很好，" + RANK_D->query_respect(ob) + 
"多加努力，他日必定有成。\n");
        command("recruit " + ob->query("id") );
}

void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "swordsman");
}
 
