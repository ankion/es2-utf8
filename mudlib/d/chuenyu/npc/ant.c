inherit NPC;

void create()
{
        set_name("螞蟻", ({ "ant" }) );
        set("race", "野獸");
        set("age", 1);
        set("long", "一隻小小的小螞蟻\n");

        set("limbs", ({ "頭部", "身體", "尾巴" }) );
        set("verbs", ({ "bite" }) );

        set_skill("dodge", 200);

        setup();
}
