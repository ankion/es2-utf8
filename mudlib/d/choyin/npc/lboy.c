inherit NPC;

void create()
{
        set_name("紫衣童子", ({ "boy" }) );
        set("gender", "男性" );
        set("age", 15);
        set("per", 30-random(15) );
        set("long",@LONG
紫衣童子是喬陰縣的小孩，從小孤苦零丁。仙人憐之，帶入雲臺。
LONG
        );
        set("combat_exp", 1200000);
        set("attitude", "friendly");
                set("chat_chance", 2);
        set("chat_msg", ({
"紫衣童子躬身一揖。 \n",
"童子說道：仙人 ，只在此山中，雲深不知處。\n", 
       }) );

                set("chat_chance_combat", 10);
                set("chat_msg_combat", ({
"紫衣童子擰眉說道：你欺負我年紀小是嗎？\n",
"紫衣童子笑道：你殺不死我的。\n",
"紫衣童子衝你一齜牙, 說道: 您盜過古墓嗎?\n",
                }) );
        set("inquiry", ([
                "仙人" : "只度有緣人。",
        ]) );

        set_skill("dodge", 150);
        set_skill("unarmed", 150);
        set_skill("mysterrier",150); 
        map_skill("dodge", "mysterrier");
        set_skill("force", 15);
        set("force", 500);
        set("max_force", 500);
        set("force_factor", 0);
        setup();

}

