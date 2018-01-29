// garrison.c

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("縣城官兵", ({ "town garrison", "garrison" }) );
        set("long",
                
"這是個正在執行公務的縣城官兵，雖然和許多武林人物比起來，官兵\n"
                
"們的武功實在稀鬆平常，但是他們是有組織、有紀律的戰士，誰也不\n"
                "輕易地招惹他們。\n");

        set("attitude", "heroism");
        set("vendetta_mark", "authority");
        set("pursuer", 1);

        set("str", 27);
        set("cor", 26);
        set("cps", 25);

        set("combat_exp", 100000);

        set("chat_chance", 10);
        set("chat_msg", ({
                (: random_move :),
        }) );

        set("chat_chance_combat", 15);
        set("chat_msg_combat", ({
                "縣城官兵喝道：還不快放下武器束手就縛？\n",
                "縣城官兵喝道：大膽刁民竟敢拒捕？反了！反了！\n"
        }) );

        set_skill("unarmed", 70);
        set_skill("sword", 70);
        set_skill("parry", 70);
        set_skill("dodge", 70);
        set_skill("move", 100);

        set_temp("apply/attack", 70);
        set_temp("apply/defense", 70);
        set_temp("apply/damage", 30);
        set_temp("apply/armor", 70);
        set_temp("apply/move", 100);

        setup();

        carry_object("/obj/cloth")->wear();
        carry_object("/obj/longsword")->wield();
}

 
