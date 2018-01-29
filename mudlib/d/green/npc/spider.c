inherit NPC;

void create()
{
	set_name("蜘蛛", ({ "spider" }) );
	set("race", "野獸");
	set("age", 1);
	set("long",@LONG
這是一隻體型相當大的蜘蛛, 看來有點嚇人.

LONG
	);
	set("str", 20);

	set("limbs", ({ "頭部", "身體" }) );
	set("verbs", ({ "bite" }) );

	set_temp("apply/attack", 15);
	set_temp("apply/armor",5);
	set_temp("apply/dodge",10);

	setup();
}
