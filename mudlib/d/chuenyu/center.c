inherit ROOM;

void create()
{
        set("short", "黑松閣正廳");
        set("long", @LONG
黑松閣正廳完全是用檀香木打造的。一陣陣的檀香飄過來，
使你心曠神夷。廳口懸着一幅字畫，寫道：“是非成敗轉頭空，
青山依舊在，幾度夕陽紅。”整幅字畫是用一條很粗的繩子掛起
來的。
LONG
        );
        set("exits", ([
        "west" : __DIR__"west_blackge",
        ]));
        set("item_desc", ([
        "rope": "這根繩子順着牆垂下來，你似乎可以拉(pull)它，但是你有一種不祥的感覺。\n",
        "繩子": "這根繩子順着牆垂下來，你似乎可以拉(pull)它，但是你有一種不祥的感覺。\n",
        ]) );
        
        
        setup();
}

void init()
{
        add_action("roping", "pull");
}

int roping(string arg)
{
        int i;
        int damage;
        object obj;
        object ob;
        object me;
        ob = this_player();
        if(!arg || arg=="")
        {
                write("你要拉什麼？\n");
                return 1;
        }
        if( arg == "rope" || arg == "繩子" )
        {
        me = this_player();
        message_vision("$N試着拉了一下繩子，觸動了翻板，整個人“轟隆”一聲掉了下去！\n", me);
        me->move(__DIR__"tunnel1");
        message_vision("$N“轟隆”一聲，從上面掉了下來！摔得你好痛！\n", me);
        i = (int)ob->query("eff_kee");
        damage = random(10)+5  ;
        ob->set("eff_kee",(int) i - damage );
        i =  (int)ob->query("kee");
        ob->set("kee",(int) i - damage);
        
        return 1;
        }
        else
        {
                write("你不可以拉"+arg+"\n");
                return 1;
        }
}
                                                