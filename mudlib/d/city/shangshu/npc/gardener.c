// gardener
#include <ansi.h>

inherit NPC;

void create()
{
        set_name("花匠", ({ "gardener" }) );
	set("gender", "男性");
	set("age", 55);
        set("long",
		"一個老老實實、本本分分的莊園花匠，多年的風霜刻滿\n"
		"了他的額頭。多年以來從來沒有人認真注意過他，他也\n"
		"總是默默地在花園裏工作。\n"
                );

        set("attitude", "peaceful");

        set("combat_exp", 500000);

        set("str", 25);
        set("int", 27);
        set("cor", 23);
        set("cps", 28);
        set("spi", 30);

        set("force", 1800);
        set("max_force", 900);
        set("force_factor", 25);

        set("atman", 1200);
        set("max_atman", 1200);

        set("mana", 3500);
        set("max_mana", 1800);
        set("mana_factor", 4);

        set("inquiry", ([
                "茅山派": 	"那是我的師門。\n",
		"林忌":		"林忌？。。你問我師兄，好久沒見着他了。\n",
		"庾清塵":	"什麼？清塵出事了？\n"
        ]) );

        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: cast_spell, "drainerbolt" :),
                (: cast_spell, "netherbolt" :),
                (: cast_spell, "feeblebolt" :),
                (: cast_spell, "invocation" :),
        }) );

        set_skill("literate", 100);
        set_skill("magic", 40);
        set_skill("force", 30);
        set_skill("spells", 90);
        set_skill("scratching", 90);
        set_skill("unarmed", 30);
        set_skill("sword", 40);
        set_skill("parry", 40);
        set_skill("dodge", 40);
        set_skill("gouyee", 60);

        set_skill("taoism", 90);
        set_skill("necromancy", 90);

        map_skill("spells", "necromancy");
	map_skill("sword", "scratching");
	map_skill("parry", "scratching");
	map_skill("force", "gouyee");

        setup();

        carry_object(__DIR__"obj/sword")->wield();
}
