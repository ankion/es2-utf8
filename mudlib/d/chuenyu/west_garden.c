inherit ROOM;

void create()
{
        set("short", "西花園");
        set("long", @LONG
你站在黑松城堡的西花園裏。花園裏長滿了各式各樣奇花異草。
西側高聳的城牆上長滿了青色的蔓藤。蔓藤從牆頂一直垂到你的腳下。
再往東則是雄偉的黑松閣。
LONG
        );
        set("exits", ([
        "east" : __DIR__"west_blackge",
        ]));
        set("item_desc", ([
        "wall": "城牆雖陡，但長滿了蔓藤。你似乎可以試着爬(climb)上去。\n",
        "城牆": "城牆雖陡，但長滿了蔓藤。你似乎可以試着爬(climb)上去。\n",
        
        "蔓藤": "蔓藤長滿了城牆，你似乎可以試着爬(climb)上去。\n"
         ]) );
         set("objects", ([
          __DIR__"npc/gardener" : 1,
          __DIR__"npc/bee" : 2,
          ]) );
          
          set("outdoors", "chuenyu");
          
          setup();
}

void init()
{
        add_action("climbing", "climb");
}

int climbing(string arg)
{
        object obj;
        object me;
        if(!arg || arg=="")
        {
        write("你要爬什麼？\n");
        return 1;
        }
        if( arg == "wall" || arg == "蔓藤" || arg == "城牆")
        {
        me = this_player();
        message_vision("$N抓着蔓藤，慢慢的順着城牆爬了上去。\n", me);
        me->start_busy(3);
         call_out("fliping",3,me);
         me->stop_busy();
         return 1;
         }
         else
         {
         write("你不可以爬"+arg+"\n");
          return 1;
          }
}

int fliping(object me)
{
        me->move(__DIR__"west_castle.c");
        message_vision("$N用手一撐牆頭兒，輕巧的跳了過來。\n", me);
        return 1;
        
}
                                            