#include <ansi.h>
inherit ITEM;

void create()
{
         set_name(HIW "舞曲譜" NOR, ({ "dance book","book" }));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "卷");
                set("long",
                        
"這是一卷由上等絲綢編成，以湘繡作成的舞曲圖。上有記載一些舞曲 \n"
"每一曲都有它獨特的風格與內涵。一幅幅玄天玉女翩然起舞，十分壯觀。\n"
 "\n  曲目： \n \n"
MAG "  廣陵散 \n" "  春宮怨 \n \n" NOR
"對你而言基本舞步你可以參悟，至於較高深步法似乎需人指導了。 \n");
                set("value", 1000);
                set("material", "silk");
                set("no_drop", 1);
                set("skill", ([
                        "name":                 "music",
                  "exp_required": 5000,
                        "sen_cost": 30,            
                     "class" : "dancer",
                        "difficulty":   20,
                        "max_skill":   60 ,
                ]) );
        }
}

void init()
{
    add_action("do_dance","dancing");
}

int do_dance(string arg)
{
    string name;
    name = (string)this_player()->query("name");

    if( !arg ) return notify_fail("你要跳什麼舞? \n");
    {
        if ( arg == "home" )
        {
            message_vision("$N雙手合掌，腳步輕盈。一曲" +
              HIM "『 春宮怨 』" NOR "......\n",this_player() );
            this_player()->receive_damage("sen",50);
            tell_room(environment(this_player()),
                 name+"的身影消失在空氣中。\n",this_player() );
            tell_room("/d/latemoon/latemoon1",
                 name+"的身影出現在一曲悽美的曲調中。\n",this_player() );
            this_player()->move("/d/latemoon/latemoon1");
         }
     }
     return 1;
}
