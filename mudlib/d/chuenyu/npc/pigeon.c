inherit NPC;

void create()
{
        set_name("信鴿", ({ "pigeon" }) );
        set("race", "野獸");
        set("age", 2);
        set("long", "一隻乖巧的小信鴿\n");

        set("limbs", ({ "頭部", "身體", "尾巴", "翅膀" }) );
        set("verbs", ({ "bite"}) );

        set_skill("dodge", 250);

        setup();
}
