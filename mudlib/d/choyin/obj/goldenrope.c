#include <ansi.h>
inherit ITEM;

void create()
{
         set_name(HIW "縛仙繩" NOR, ({ "golden rope","rope" }));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "條");
                set("long",@LONG
這是一條由上等金絲編成的繩索, 可縛(tie)禽獸鬼怪。上刻有無數咒文，發出耀目金光.
LONG );
                set("value", 1000);
                set("no_drop", 1);
              
        }
}

void init()
{
    add_action("do_tie","tie");
}

int do_tie(string arg)
{
    string name;
    name = (string)this_player()->query("name");

    if( !arg ) return notify_fail("你要縛何物? \n");
    {
        if ( arg == "crane" )
        
            message_vision("$N雙手合掌，隨風而起，落於仙鶴背上......\n",
            this_player() );
            this_player()->receive_damage("sen",50);
            tell_room(environment(this_player()),
                "仙鶴的身影扶搖直上，消失於雲端。\n",this_player() );
            tell_room("/d/choyin/platform",
                 name+"的身影出現在雲霧中。\n",this_player() );
            this_player()->move("/d/choyin/platform");
         }
     return 1;
}
