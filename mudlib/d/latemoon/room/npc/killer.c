// killer.c

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("殺手", ({ "killer" }) );
        set("title","蒙面殺手" );
        set("gender","女性" );
        set("age",23);
        set("long",
                
"這是個蒙面殺手，眉眼看起來有些面熟。\n");

//        set("vendetta_mark", "authority");
        set("pursuer", 1);

        set("str", 27);
        set("cor", 26);
        set("cps", 15);
        set("per", 28);

        set("combat_exp", 12000);

        set("chat_chance", 10);
        set("chat_msg", ({
                (: random_move :),
        }) );

        set("chat_chance_combat", 10);
        set("chat_msg_combat", ({
                "蒙面殺手喝道：爲什麼殺我？\n",
                "蒙面殺手嘆道：你知道我心裏有多痛苦嗎？！\n"
        }) );

        set_skill("unarmed",40);
        set_skill("sword", 40);
        set_skill("parry", 40);
        set_skill("dodge", 20);
        set_skill("move", 30);
        set_skill("six-chaos-sword",27);
        set_skill("pyrobat-steps",20);
        map_skill("dodge","pyrobat-steps");
        map_skill("sword","six-chaos-sword");


        set_temp("apply/attack", 20);
        //set_temp("apply/defense", 70);
        //set_temp("apply/damage", 10);
        //set_temp("apply/armor", 70);
        //set_temp("apply/move", 30);

        setup();

        carry_object("/d/snow/npc/obj/pink_cloth")->wear();
        carry_object("/d/snow/npc/obj/thin_sword")->wield();
        carry_object("/d/latemoon/room/npc/obj/token");
}

