inherit NPC;
 
void create()
{
         set_name("苗鬱淑", ({ "yushou","yu","shou" }) );
        set("gender", "女性" );
        set("age",18);
        set("long", @TEXT
她看起來很有活力，兩眼明亮有神。給你
一種巾幗不讓鬚眉的氣勢，但剛毅之中似
又隱含著女孩子有的嬌柔。
TEXT
);
       set("class", "dancer");
       set("combat_exp", 15000);
        set_skill("unarmed",40);
        set_skill("dodge", 40);
        set_skill("stormdance", 50);
        set_skill("tenderzhi", 60);
        set_skill("force",50);
        map_skill("dodge","stormdance");
        map_skill("unarmed","tenderzhi");
        set("force", 400);
        set("max_force", 400);
        set_temp("apply/armor", 100);

       create_family("晚月莊",3,"弟子");
        setup();
        carry_object(__DIR__"obj/earring")->wear();
        carry_object(__DIR__"obj/brooch")->wear();
}

void init()
{
       object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        if( !ob || !present(ob, environment(this_object())) ) return;
        command("close door");
        say ("閣下! 這裏是莊內後廳廂房。不方便男客進入哦! \n" +
              "請隨手關門，並保持安靜! 謝謝! \n" );
}
