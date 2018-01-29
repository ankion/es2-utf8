inherit ROOM;

void create()
{
        set("short", "黑松城堡的東側");
        set("long", @LONG
你站在黑松山頂，黑松城堡的東側。高聳的城牆上長滿了青色的
蔓藤。蔓藤從牆頂一直垂到你的腳下。再往東是刀削般的萬丈懸崖。
往西則是城堡的正門。你腳下是一塊青石板。
LONG
        );
        set("exits", ([
                "west" : __DIR__"gate_castle",
        ]));
        
        set("item_desc", ([
        "wall": "城牆雖陡，但長滿了蔓藤。你似乎可以試着爬(climb)上去。\n",
        "城牆": "城牆雖陡，但長滿了蔓藤。你似乎可以試着爬(climb)上去。\n",
        "青石板": "青石板勞牢的鑲在地下，但它下面似乎是空的。\n",
        "rock" : "青石板勞牢的鑲在地下，但它下面似乎是空的。\n",
        "蔓藤": "蔓藤長滿了城牆，你似乎可以試着爬(climb)上去。\n"
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
        me->move(__DIR__"east_garden.c");
        message_vision("$N用手一撐牆頭兒，輕巧的跳了過來。\n", me);
        return 1;
}

                                                                         