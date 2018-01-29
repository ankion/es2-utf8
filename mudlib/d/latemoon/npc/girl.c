inherit NPC;
 string show_dance();
string show_dragon();
 
void create()
{
        set_name("昭儀", ({ "zauyi", "joe" }) );
        set("title", "晚月莊第三代弟子");
        set("gender", "女性" );
        set("age",17);
        set("long", @TEXT
她看起來非常可愛。身材玲瓏有致，曲線苗條。
第一眼印象，你覺的她舞蹈一定跳的不錯，看她的一舉一動
有一種說不出的流暢優雅！
TEXT
);
       set("class", "dancer");
        set("combat_exp", 4000);
        set("kee",270);
        set("san",100);
        set_skill("unarmed",20);
        set_skill("unarmed", 30);
        set_skill("dodge", 30);
        set_skill("blade",10);
         set_skill("spring-blade",7);
        map_skill("blade", "spring-blade");
        set_skill("force",50);
        set("force",450);
       set("max_force",450);
        set("force_factor", 2);
        set_temp("apply/armor", 30);
        set("inquiry", ([
         "圖" : "這是一張非常真貴的湘繡舞曲圖，我也在研究中。\n",
         "滄海龍吟" : "嗯 ...爲這舞曲名。似乎雨梅姊知道。\n",
         "有鳳來儀" : "嗯 ...爲這舞曲名。(dancing yu-fong)很有名！ \n",
         "西出陽關" : "「幻影式舞步」步法與地點都很重要。\n",
         "芳綾" : "她聰明伶俐，會跳一些自創的舞步。\n",
         "畫" : "滄海龍吟是一幅湘繡舞曲圖，記載一些珍貴舞步。\n",
            "寒谷龍舞" : (: this_object(), "show_dance" :),
            "舞" : (: this_object(), "show_dragon" :)
        ]));
        setup();
        set("chat_chance", 8);
        set("chat_msg", ({
"昭儀以輕妙的舞步，在房內跳了起來!你看的入神。\n",
"昭儀擡頭望著那幅圖畫，略有所思... \n"
        }) );
      carry_object(__DIR__"obj/yu_blade")->wield();
      carry_object(__DIR__"obj/flower_boot")->wear();
}

string show_dance()
{
        object me;
        string str;
        str = (string)this_object()->query("name");
        me = this_player();
        tell_object(me, str+"很奇怪的望著你，說道:嘻!你對舞有興趣呀! \n");
        tell_object(me,"只見兩眼溜來溜去，一種很神祕的表情，嘟著嘴。\n");
        tell_object(me,"過了一會說：好吧!偷偷跟你說，你可以查看牆上"
     +"的圖。(dragon-dance) \n");
        return "....\n";
}
string show_dragon()
{
      object me;
      string str;
      str = (string)this_object()->query("name");
      me = this_player();
      tell_object(me, str+"很高興的看著你，說道:嘻!你對舞有興趣呀!\n");
      tell_object(me,"這有一幅圖畫，我從那悟到好多新舞步哦! \n");
      tell_object(me,"『 滄海龍吟』是一首失傳以久的舞曲。傳說....\n");
      return "......\n";
}

