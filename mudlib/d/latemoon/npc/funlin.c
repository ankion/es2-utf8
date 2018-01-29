inherit NPC;
 
void create()
{
        set_name("芳綾",  ({ "funlin","fun","lin" }) );
        set("gender", "女性" );
        set("age",18);
        set("long", @TEXT
她看起來像個小靈精，頭上梳兩個小包包頭。
她坐在地上，看到你看她便向你作了個鬼臉!
你想她一定是調皮纔會在這受罰!
TEXT
);
       set("class", "dancer");
       set("combat_exp", 2000);
        set_skill("unarmed", 20);
        set_skill("whip", 20);
        set_skill("dodge", 20);
        set_skill("move", 30);
        set_skill("stormdance", 20);
        map_skill("dodge","stormdance");
        set_skill("dodge", 30);
        set_skill("force", 15);
        set("force", 500);
        set("max_force", 300);
        set("force_factor", 2);
        set_temp("apply/armor", 30);

         set("chat_chance", 7);
       set("chat_msg", ({
"頑皮的芳綾向你扮個鬼臉。  *^G^* \n",
"芳綾走到中央，一個姿勢(Pose)。哇!你沒想到她跳舞時竟有此深造詣。\n",
"芳綾說：好不好看！這可是我花好久練成的哦! \n",
"芳綾緩緩的移動著，手上的動作變化萬千，有一種說不出的美妙。\n",
"芳綾說：你好煩哦! 快走開! \n",
"芳綾說：你想學可以去問昭儀姐，她會的比我多。嘻! \n",
"芳綾說：醜八怪! 不要煩我。走開啦! \n",
"她嘟著嘴。有點生氣的翻過頭去，不理你！\n"
       }) );
       create_family("晚月莊",5,"弟子");
        setup();
        carry_object(__DIR__"obj/whip")->wield();
        carry_object(__DIR__"obj/deer_boot")->wear();
        carry_object(__DIR__"obj/skirt5")->wear();
}

int accept_object(object who, object ob)
{
     object me;
     string objname;

     me = this_player();
     objname = (string)ob->name();

        if ( objname != "竹蜻蜓")  {
           command("smile");
            say ("這要送給我啊?! 怎麼好意思!謝謝你。\n");
           command("blush");
             return 1;
            }
        if( !who->query_temp("moon/竹蜻蜓") )  {

            tell_object(me, "芳綾很開心的拿起竹蜻蜓把玩!\n\n");
            tell_object(me, "滿懷感激的謝謝你! 她小聲的在你耳邊說：\n");
            tell_object(me, "『 莊內前廳某處藏有一寶物手鐲哦!』\n");
            tell_object(me, "你可以找找看! (search bracelet) \n");
            who->set_temp("moon/問題二", 1);
            who->set_temp("moon/竹蜻蜓", 1);
         } else {
             say ("謝謝!我已經告訴你祕密了呀!去找呀! \n");
             return 1;
          }
          return 1;
}
