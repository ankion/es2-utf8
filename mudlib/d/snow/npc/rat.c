// fly.c

inherit NPC;

void create()
{
        set_name("老鼠", ({ "rat" }) );
        set("race", "野獸");
        set("age", 1);
        set("long", "一隻賊頭賊腦的大老鼠。\n");

        set("limbs", ({ "頭部", "身體"}) );
        set("verbs", ({ "bite" }) );

        set_skill("dodge", 120);

        setup();
}
