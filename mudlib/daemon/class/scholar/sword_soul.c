// sword_soul.c

#include <ansi.h>

inherit NPC;

void create()
{
        set_name( HIW "風泉劍靈" NOR, ({ "sword soul", "soul" }) );
        set("long", "一個高大的人形，只有輪廓發出暗藍色的光芒，其他部份都是透明的！\n");
        set("age", 19);
        set("gender", "女性");
        set("attitude", "heroism");

        set("max_gin", 2000);
        set("max_kee", 2000);
        set("max_sen", 2000);

        set("str", 80);
        set("con", 70);
        set("cor", 40);
        set("spi", 40);
        set("int", 20);
        set("cps", 90);
        set("kar", 80);
        set("per", 50);

        set_temp("apply/attack", 100);
        set_temp("apply/damage", 100);
        set_temp("apply/defense", 100);
        set_temp("apply/armor", 120);
        set_temp("apply/armor_vs_force", 1000);

        set_skill("sword", 150);
        set_skill("parry", 150);

        set("combat_exp", 300000);

        setup();
	carry_object(__DIR__"windspring")->wield();
}

void chant()
{
        call_out("chant_sword", 20, 1);
}

static void chant_sword(int stage)
{
        switch(stage) {
                case 1:
                        command("say 劍氣指天 ...");
                        call_out("chant_sword", 20, 2);
                        break;
                case 2:
                        command("say 劍心內斂 ...");
                        call_out("chant_sword", 20, 3);
                        break;
                case 3:
                        command("say 劍芒遊光 ...");
                        call_out("chant_sword", 20, 4);
                        break;
                case 4:
                        command("say 劍神如意！");
                        message_vision("一陣藍光籠罩住$N，「嗡」地一聲，$N的輪廓又變清晰了一些！\n", this_object());
                        add("combat_exp", 100000);
                        call_out("chant_sword", 60, 1);
                        break;
        }
}
