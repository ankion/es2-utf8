
inherit NPC;

void create()
{
     set_name("小沙彌", ({"bonze"}));
     set("gender", "男性");
     set("class", "bonze");
     set("age",15);
     set("long","一個天真無邪的小和尚, 一顆圓滾滾光溜溜可愛的小光頭, 讓人看了\n"
                "就十分的喜歡他。他正在爲油燈添上香油。\n");
     set("combat_exp",800);
     set("attitude", "friendly");

     set("max_force", 400);
     set("force", 600);
     set("force_factor", 1);

     set_skill("force",30);
     set_skill("unarmed",20);
     set_skill("dodge",25);
     set_skill("buddhism",50);
     set_skill("lotusforce",30);
     
     map_skill("force", "lotusforce");
     
     setup();

     carry_object(__DIR__"obj/cloth")->wear();
     carry_object(__DIR__"obj/shoe")->wear();
}

int accept_fight(object me)
{
     command("say 師父! 救命啊!!  啊....不要打我..:( \n");
     return 0;
}
