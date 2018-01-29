// mind_beast.c

inherit NPC;

void create()
{
        set_name("巨型犬", ({ "wolf dog", "dog" }) );
        set("race", "野獸");
        set("gender", "雄性");
        set("age", 3);
        set("long", "這是一隻兇猛無比，半人多高的巨型狼犬\n");

        set("str", 48);
        set("cor", 52);
        set("cps", 22);

        set("max_kee", 600);
        set("max_gin", 600);
        set("max_sen", 900);
        set("attitude", "killer");
        set("limbs", ({ "頭部", "身體", "前腳", "後腳", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );

        set("chat_chance", 15);
        set("chat_msg", ({
"狼犬向你瘋狂的哮道：嗚汪！嗚汪！嗚汪！嗚汪！",
        }) );
                set("chat_msg_combat", ({
"狼犬向你瘋狂的哮道：嗚汪！嗚汪！嗚汪！嗚汪！",
        }) );

                set("combat_exp", 20000);
                set("bellicosity", 3000 );

        set_temp("apply/attack", 60);
        set_temp("apply/armor", 40);

        setup();
}
