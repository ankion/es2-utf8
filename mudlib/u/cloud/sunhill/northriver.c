// Room: /u/sunhill/northriver.c

inherit ROOM;

void cross_river();
void no_boat();

void create()
{
        set("short", "泓水北側");
        set("long", @LONG
這裏已靠近北岸，江水齊胸深，偶爾一個湍流捲過來，彷彿要將人
打入江底似的。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "north" : "/u/cloud/dukou",
  "south" : __DIR__"midriver",
]));
        set("outdoors", "cloud");

        setup();
        replace_program(ROOM);
}

void init()
{
        cross_river();
}

void cross_river()
{
        if( this_object()->query("marks/船伕") ) {
                set("exits/south", __DIR__"sunhill/midriver");
                call_out("no_boat", 5);
        }
}

void no_boat()
{
        if( !query("exits/south") ) return;
        message("vision","小船駛向江南。\n", this_object() );
        delete("exits/south");
	this_object()->set("marks/船伕", 0);
}

