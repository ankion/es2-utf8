// shiao.c

inherit NPC;

void create()
{
	set_name("小兵", ({ "guard" }) );
	set("gender", "男性");
	set("age", 24);
	set("long",
        	"風沙滿面，無精打采，毫無生氣的樣子，真難以想像是這\n"
                "□的守軍。\n");

	set("attitude", "peaceful");

	set("str", 26);
	set("int", 24);

	set("combat_exp", 40000);
	
	set("force", 300);
	set("max_force", 300);
	set("force_factor", 5);
	
	set_skill("unarmed", 40);
	set_skill("parry", 60);
	set_skill("dodge", 50);

	setup();

}
