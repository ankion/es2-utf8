// servant.c

inherit NPC;

void create()
{
	set_name("僕役", ({ "servant" }) );
	set("gender", "男性");
	set("age", 34);
	set("long", "這個人看起來十分和藹可親，看起來不像是會武功\的人。\n");

	set("attitude", "friendly");
	set("combat_exp", 100);

	set("str", 25);
	set("cor", 23);
	set("cps", 23);
	set("con", 27);

	setup();
}
