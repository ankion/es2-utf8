// Room: /d/snow/weapon_storage.c

inherit ROOM;

void create()
{
        set("short", "地牢");
        set("long", @LONG
這裏黑黑暗暗，幾乎伸手不見五指。唯一的光亮來自牆上忽明忽暗的
松油燈。地上和牆上佈滿了暗紅色的血痕，散發出陣陣腥氣。不斷傳來的
哀嚎聲在死沉的地牢裏迴盪，令人毛骨聳然。地牢的天花板上鑲着一塊石
板，從石板的縫隙間射進幾束陽光。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
        "north": __DIR__"tunnel5",
          "east": __DIR__"tortureroom",
            "west" : __DIR__"tortureroom2",
              "south" : __DIR__"dungeon",
                      ]));
         set("item_desc", ([
         "rock": "很沉重的石板，但你似乎可以推動它。\n",
         "石板":"很沉重的石板，但你似乎可以推動它。\n"
         ]) );
         
         setup();
}

void init()
{
        add_action("do_push", "push");
}

void check_trigger()
{
        object room;
        if( (int)query("trigger")==5//13
        &&      !query("exits/up") ) {
                message("vision", 
"石板終於被推的斜立起來，露出一個向上的縫隙。\n",
                        this_object() );
                set("exits/up", __DIR__"east_castle");
        if( room = find_object(__DIR__"east_castle") ) {
                message("vision",
"地下的石板被推的斜立起來，露出一條窄縫。\n",
                        room );
                        room->set("exits/down", __FILE__);
        }
                 delete("trigger");
                 call_out("close_passage", 5);
        }
}

void close_passage()
{
        object room;
        
        if( !query("exits/up") ) return;
        message("vision", 
"石板“轟”的一聲又倒了下來，將向上的通道蓋住了。\n", this_object());
        if( room = find_object(__DIR__"east_castle") ) {
                message("vision", 
"石板“轟”的一聲又倒了下去，將向下的通道蓋住了。\n",
                        room );
                room->delete("exits/down");
        }
        delete("exits/up");
}


int do_push(string arg)
{
        string dir;
        
        if( !arg || arg=="" ) 
        {
        write("你要推什麼？\n");
        return 1;
        }
        
        if( arg=="rock" || arg == "石板") {
        add("trigger", 1);
        write("你試著往上用力推動石板，石板變得越來越鬆動了....\n");
        check_trigger();
        return 1;
        }
}


void reset()
{
        ::reset();
        delete("trigger");
}
                                                                                                                                                                                       
