// fly.c

inherit NPC;

void create()
{
        set_name("蒼蠅", ({ "fly" }) );
        set("race", "野獸");
        set("age", 1);
        set("long", "一隻綠頭金翅的大蒼蠅。\n");

        set("limbs", ({ "頭部", "身體", "翅膀" }) );
        set("verbs", ({ "bite" }) );

        set_skill("dodge", 100);

        setup();
}

