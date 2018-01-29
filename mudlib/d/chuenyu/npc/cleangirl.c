// worker.c

inherit NPC;

void create()
{
        set_name("女傭人", ({ "cleaning maid", "maid" }) );
        set("gender", "女性" );
        set("age", 43);
        set("long", "滿臉風霜的女傭人\n");
        set("combat_exp", 700);
        set("attitude", "friendly");
        set_skill("unarmed", 10);
        set_skill("parry", 25);
        set_skill("dodge", 35);
        set_skill("throwing", 20);

        set("inquiry", ([
                "小娟" : "這要到地牢去找。", 
                "淳于" : "這要到地牢去找。",
                "淳于懷太" : "這要到地牢去找。",
                "堡主" :"這要到地牢去找。",
        ]) );

        setup();
        add_money("coin", 15);
        carry_object("/obj/cloth")->wear();
        carry_object(__DIR__"obj/feather")->wield();
}

