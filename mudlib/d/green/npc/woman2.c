// Mon  08-21-95

inherit NPC;

void create()
{
        seteuid(getuid());
        set_name("婦人",({"woman"}));
        set("gender","女性");
        set("age",40);
        set("combat_exp",50);
        set_temp("apply/dodge",3);
        add_money("coin",100);
        set("chat_chance",7);
        set("chat_msg", ({
        "婦人說道：我說啊, 管管你們家那小鬼啊.\n",
        "婦人說道：明知山洞那邊鬧鬼, 沒事帶著我們家那兩個跑過去.\n",
        "婦人打開鍋蓋\聞了一下.\n",
        "婦人朝門外看了看.\n",
        }) );
        setup();
        carry_object("/obj/cloth")->wear();
}
