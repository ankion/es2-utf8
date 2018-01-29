// executioner.c

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("潘軍禪", ({ "master executioner", "executioner", "master" }) 
);
        set("title", "水煙閣執法使");
        set("nickname", HIC "書 劍 俠" NOR);
        set("gender", "男性");
        set("age", 28);
        set("long",
                
"潘軍禪是當今武林的一位傳奇性人物，以他僅僅二十八歲的年齡竟能做到\n"
                
"水煙閣執法使的職位，著實是一位不簡單的人物。潘軍禪是封山劍派掌門\n"
                
"柳淳風的結拜義弟，但是他爲人其實十分風趣，又好交朋友，絲毫不會擺\n"
                "出武林執法者的架子。\n" );

        set("attitude", "friendly");
        set("combat_exp", 1000000);
        set("score", 200000);

        set("str", 30);
        set("int", 30);
        set("cor", 30);
        set("cps", 30);
        set("con", 30);

        set("force", 2000);
        set("max_force", 2000);
        set("force_factor", 2);

        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :),
        }) );

        set_skill("force", 100);
        set_skill("unarmed", 100);
        set_skill("sword", 100);
        set_skill("parry", 100);
        set_skill("dodge", 100);

        set_skill("celestial", 100);
        set_skill("celestrike", 100);
        set_skill("pyrobat-steps", 100);
        set_skill("six-chaos-sword", 100);

        map_skill("force", "celestial");
        map_skill("unarmed", "celestrike");
        map_skill("sword", "six-chaos-sword");
        map_skill("dodge", "pyrobat-steps");

        setup();

        carry_object(__DIR__"soulimpaler")->wield();
}

 
