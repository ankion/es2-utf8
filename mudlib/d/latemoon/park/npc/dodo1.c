inherit NPC;

void create()
{
        set_name("小金鼠", ({ "dodo" }) );
        set("race", "野獸");
        set("age", 1);
        set("long", "一隻可愛的長尾巴的小金鼠。 \n");

        set("str", 20);
        set("cor", 17);

         set("combat_exp", 1000);
        set("score", 10);
        set("dodge",20);

        set("attitude","friendly");

        set("limbs", ({ "頭部", "身體", "前腳", "後腳", "尾巴" }) );
         set("verbs", ({ "bite" ,"claw" }) );
        set_temp("armor", 10);

    set("chat_chance", 15);
    set("chat_msg", ({
            (: this_object(), "random_move" :),
"小金鼠搖搖尾巴!全身晃呀晃! \n",
"小金鼠眼睛眨呀眨!好像快睡著了! \n",
"嘟嘟玩太累了!睡著了! \n",
"小金鼠「嘟嘟」它跳啊跳的! \n",
"小金鼠「嘟嘟」眼睛眨呀眨看著你 \n",
"小金鼠發出「  嘰! 嘰!」」的叫聲! \n"
    }) );

        setup();
}
