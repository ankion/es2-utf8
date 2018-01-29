// xiaojuan2.c

inherit NPC;

void create()
{
        set_name("小娟", ({ "xiao juan","juan" }) );
        set("title", "民女");
        set("gender", "女性" );
        set("age", 16);
        set("str", 1);
        set("per", 30);
        set("long", @LONG
小娟姓劉，是這裏劉老農的獨生女。今年十六歲，人長的漂靚又大方。
小娟已經被折磨的遍體鱗傷。
LONG
);
        set("max_gin", 500);
        set("eff_gin", 1);
        set("gin", 1);
        set("max_kee", 500);
        set("eff_kee", 1);
        set("kee", 1);
        set("max_sen", 500);
        set("eff_sen", 1);
        set("sen", 1);
        set("score", -500);
        set("combat_exp", 1);
        set("attitude", "friendly");

        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
"小娟說道：唉！ 沒料道你和那些壞人是一夥的！\n",
        }) );

        setup();

        carry_object(__DIR__"obj/torn_pink_cloth")->wear();
}


int accept_fight(object me)
{
        command("say 小女子哪裏是您的對手？");
        return 0;
}


void init()
{
        object ob;
        if( interactive( ob = this_player()))
        remove_call_out("followhim");
        if((int) ob->query("marks/老劉本人") == 1)
        {
        set_leader(0);
        call_out("goaway", 5);
        }
        else {
        call_out("messageing",3);
        call_out("followhim", 20, ob);
        }
}
void messageing()
{
        object room;
        room = find_object(__DIR__"dungeon");
        if(environment() == room) {
        command("say 救我！救救我呀！");
        command("emote 竭力掙扎，漸漸從繩索裏擺脫出來……。");
}
}
void followhim(object ob)
{
object room;
room = find_object(__DIR__"dungeon");
if(environment() == room)
if( present(ob, environment()))
{       set_leader(ob);
        ob->set("marks/老劉", 1);

}
}

void goaway()
{
destruct(this_object());
}

void die()
{
        int i;
        object killer;

        if(objectp(killer = query_temp("last_damage_from")))
            killer->set("marks/murder", 1);

        ::die();

}
