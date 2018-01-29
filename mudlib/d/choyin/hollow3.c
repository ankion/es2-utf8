inherit ROOM;

void create()
{
        set("short", "寒谷盡頭");
        set("long", @LONG
兩面皆爲峭壁，光滑無物。一株寒谷幽蘭,暗香浮動，沁人心脾。山壁天然行成
一空穴(vase),積滿寒露.
LONG
        );
        set("item_desc", ([
                "vase":
                    "石穴呈瓶狀,想是用來插(interject)什麼東東的.\n",
                          ]) );
        set("exits", ([ /* sizeof() == 1 */
                "east" : __DIR__"hollow1",
]));
        set("objects", ([ /* sizeof() == 1 */
                  __DIR__"obj/orchid" : 1,
]));
        set("no_magic", 1);

        setup();

}

void init()
{
        add_action("do_interject", "interject");
}
int do_interject(string arg)
{
        if( !arg || arg!="orchid" ) return notify_fail ("你要用什麼？\n");
        message_vision("寒谷幽蘭忽地綻放,幻出七色光華.$N輕輕地飄起...\n",
                this_player());
        tell_room("/d/latemoon/bamboo",this_player()->query("name") + "輕輕飄落.\n");
        this_player()->move("/d/latemoon/bamboo");
        return 1;
}
