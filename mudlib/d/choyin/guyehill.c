#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short","絕壁");
        set("long",@LONG
    採藥人言曰：有仙人乘鶴飛昇，徑入此山，不知所終.....
此地林木(tree)繁茂，藤蔓(vine)錯雜。南聳絕壁，下臨深谷.
半山腰處，隱隱可見一洞，流雲出岫。
LONG
       );
        set("item_desc", ([
                "vine":
                    "其中有一根藤蔓距離你比較近，你可以試著抓住(hold)藤蔓\n",

                "tree":
                    "這是一株萬年古樹，尋常人等休想爬得上去.\n"

                          ]) );
        set("exits", ([ /* sizeof() == 1 */
                "northdown" : __DIR__"rockroad",
                      ]));
        set("outdoors", "choyin");
        setup();
}

void init()
{
        add_action("do_climb", "climb");
        add_action("do_hold", "hold");  
}
int do_climb(string arg)
{
        if( !arg || arg!="tree" ) return 0;
        message_vision("$N七手八腳地爬上了古樹。\n",
                this_player());
        tell_room(__DIR__"craneroom",this_player()->query("name") + "樹下爬了上來。\n");
        this_player()->move(__DIR__"craneroom");
        return 1;
}

int do_hold(string arg)
{
        if( !arg || arg!= "vine" )
                return notify_fail("你要抓住什麼？\n");
        message_vision("$N伸手往不遠處的一根藤蔓抓去....\n\n",
                this_player());
        if( random((int)this_player()->query_skill("dodge")) < 30 ) {
                message_vision("\n只聽見一聲殺豬般的慘叫，$N已墜落深谷。。\n\n
", this_player());  
        this_player()->move(__DIR__"hollow");        
      } else {
                message_vision("$N手腳俐落地攀附著藤蔓，慢慢地爬近山洞。\n\n",
                      this_player() );
        this_player()->move(__DIR__"halfhole");  
        }
        return 1;
}

