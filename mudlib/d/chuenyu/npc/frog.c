
inherit NPC;

void create()
{
        set_name("蛐蛐", ({ "insect" }) );
        set("race", "野獸");
        set("age", 1);
        set("long", "一隻方頭方腦的大蛐蛐\n");

        set("limbs", ({ "頭部", "身體", "尾巴" }) );
        set("verbs", ({ "bite" }) );

        set_skill("dodge", 150);

        setup();
}

