// Room: /d/chuenyu/rope_bridge.c

inherit ROOM;

void create()
{
// this place can check on player's dodge, if toolow, drop them!
        set("short", "鐵索橋");
        set("long", @LONG
山頂強勁的風吹得鐵索橋左右晃動，腳下的萬丈深淵使你頭暈目旋。
你竭盡全力的維持身體平衡。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
        "west" : __DIR__"high_b_mtn",
          "east" : __DIR__"high_b_mtn2",
          ]));
          set("objects", ([
          __DIR__"npc/jiading3" : 2,
          ]) );
          
          
          set("outdoors", "chuenyu");
          
          setup();
}

void init()
{
        add_action("do_climb", "climb");
}

int do_climb(string arg)
{
        if( !arg || arg!="chain" ) 
	{
	     write("這裏只有一條鐵鏈（chain）。\n");
             return 1;
	}

        message_vision("$N抓緊鐵鏈，順着鐵索橋走了下去。\n",
                this_player() );
        this_player()->move(__DIR__"base_b_m");

        return 1;
}
                  
