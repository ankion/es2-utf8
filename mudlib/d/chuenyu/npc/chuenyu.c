// chuenyu.c

inherit NPC;

string kill_passenger(object who);

void create()
{
        set_name("淳于懷太", ({ "chunyu" }) );
        set("gender", "男性" );
        set("title", "淳于堡主");
        set("age", 47);
        set("str", 27);
        set("int", 12);
        set("per", 10);
        set("long", @LONG
淳于懷太是強盜出身，年輕時打家劫舍，無惡不做。尤於生
性惡頑，沒人願收其爲徒。但他絕頂聰明，盜百家之長而集
於一身。
LONG
);
        set("attitude", "killer");


        set("combat_exp", 10000);
        set("bellicosity", 3000 );
        set("chat_chance", 50);
        set("chat_msg", ({
"淳于懷太喝道：呔！你竟敢壞大爺的好事！\n",
         }) );
        set_skill("unarmed", 60);
        set_skill("whip", 30);
        set_skill("dodge", 40);
        set_skill("parry", 30);
        set_skill("snowwhip", 80);
        set_skill("liuh-ken", 20);
        set_skill("pyrobat-steps", 100);
        map_skill("whip", "snowwhip");
        map_skill("unarmed","liuh-ken");
        map_skill("dodge", "pyrobat-steps");
        set("score", 100);

        setup();

        add_money("gold", 50); 
        carry_object(__DIR__"obj/chwhip")->wield();
}
void init()
{
        object ob;
        ::init();
        if( interactive(ob = this_player()) ) {
        message_vision("淳于懷太喝道：呔！你竟敢壞大爺的好事！\n",ob);
                kill_ob(ob);
        }
}

