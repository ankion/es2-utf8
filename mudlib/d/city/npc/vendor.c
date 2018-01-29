//vendor.c

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("賣藝壯漢", ({ "vendor man","man" }) );
        set("gender", "男性" );
        set("age", 34);
        set("long", "一個滿臉橫肉的壯漢，口水四濺，正說着什麼。\n");
        set("combat_exp", 30000);
        set("attitude", "friendly");
        set("vendor_goods", ([
                "medicine": "/obj/drug/hurt_drug",
        ]) );
        set("chat_chance", 20);
        set("chat_msg", ({
                "賣藝壯漢吆喝道：出外靠朋友，諸位請捧個錢場！\n",
                "賣藝壯漢練了一套六陰劍，還象模象樣。\n",
                "賣藝壯漢低聲對你說道：在下剛路過八舍！\n",
        }) );
        set("inquiry", ([
                "金瘡藥" : (: do_vendor_list :),
        ]) );
        setup();
}

void init()
{
        ::init();

        add_action("do_vendor_list", "list");
}

