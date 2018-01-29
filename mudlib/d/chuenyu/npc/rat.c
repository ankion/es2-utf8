inherit NPC;

void create()
{
        set_name("大老鼠", ({ "rat" }) );
        set("race", "野獸");
        set("age", 5);
        set("long", "一隻鼠頭鼠腦的大老鼠\n");

        set("limbs", ({ "頭部", "身體", "尾巴" }) );
        set("verbs", ({ "bite" }) );

        set_skill("dodge", 80);

        setup();
}
