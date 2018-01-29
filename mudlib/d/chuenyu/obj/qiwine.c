inherit ITEM;
inherit F_LIQUID;

void create()
{
        set_name("人皮酒袋", ({ "wineskin", "skin" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一個人皮縫的大酒袋，大概裝得八、九升的酒。\n");
                set("unit", "個");
                set("value", 50);
                set("max_liquid", 20);
        }

        // The liquid contained in the container is independent, we set a copy
        // in each cloned copy.
        set("liquid", ([
                "type": "alcohol",
                "name": "竹葉青",
                "remaining": 20,
                "drunk_apply": 10,
        ]) );
}
