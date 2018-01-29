// garrison.c

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("守城官兵", ({ "town guard", "guard" }) );
	set("long",
		"這是個正在這裏站崗的守城官兵，雖然和許\多武林人物比起來，官兵\n"
		"們的武功\實在稀鬆平常，但是他們是有組織、有紀律的戰士，誰也不\n"
		"輕易地招惹他們。\n");

	set("attitude", "peaceful");
	set("vendetta_mark", "authority");

	set("str", 27);
	set("cor", 26);
	set("cps", 25);

	set("combat_exp", 100000);

	set("chat_chance_combat", 15);
	set("chat_msg_combat", ({
		"守城官兵喝道：還不快放下武器束手就縛？\n",
		"守城官兵喝道：大膽刁民！竟敢殺官造反？\n"
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

