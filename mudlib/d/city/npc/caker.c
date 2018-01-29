// cake_vendor.c

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("賣餅大叔", ({ "cake vendor", "vendor" }) );
        set("gender", "男性" );
        set("age", 42);
        set("long", "一個相貌樸實的賣餅大叔，憨厚的臉上掛著和藹的笑容。\n");
        set("combat_exp", 30);
        set("attitude", "friendly");
        set("rank_info/respect", "大叔");
        set("rank_info/self", "小的");
        set("vendor_goods", ([
              "big cake": __DIR__"obj/cake",
        ]) );
        set("chat_chance", 13);
        set("chat_msg", ({
                "賣餅大叔吆喝道：賣餅喲！又香又脆的大餅喲！\n",
                "賣餅大叔掀開蒸籠，伸手探了探溫度。\n",
                "賣餅大叔吆喝道：剛出爐的大餅喲！熱呼呼的大餅喲！\n",
        }) );
        set("inquiry", ([
                "大餅" : (: do_vendor_list :),
        ]) );
        setup();
}

void init()
{
        ::init();

        add_action("do_vendor_list", "list");
}

