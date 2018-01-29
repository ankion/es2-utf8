inherit NPC;

void create()
{
     set_name("玄和",({"shyuan-her","shyuan","her"}) );
     set("gender", "男性");
     set("age", 14);
     set("attitude", "heroism");
     set("long",
     "一個長得眉清目秀的小男孩, 正忙著澆花除草\n");
     set("title", "茅山派第八代弟子");
     set("class", "taoist");
     set("combat_exp",1000);
     set("str",25);
     set("max_kee", 350);
     set("max_force", 200);
     set("force",200);
     set("force_factor", 2);
     set("mana", 100);
     set("max_mana", 100);
     set("sen", 150);
     set("max_sen",150);
     set_skill("force", 20);
     set_skill("spells",15);
     set_skill("unarmed", 20);
     set_skill("dodge", 15);
     set_skill("parry", 18);
     setup();
     carry_object(__DIR__"obj/robe")->wear();
     carry_object(__DIR__"obj/boots")->wear();
}
