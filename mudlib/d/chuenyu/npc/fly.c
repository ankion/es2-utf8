inherit NPC;

void create()
{
        set_name("蝴蝶", ({ "butterfly" }) );
        set("race", "野獸");
        set("age", 1);
        set("long", "一隻美麗的小蝴蝶\n");

        set("limbs", ({ "頭部", "身體", "尾巴" }) );
        set("verbs", ({ "bite" }) );

        set_skill("dodge", 250);

        setup();
}

