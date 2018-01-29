#include <ansi.h>

#include <armor.h>
inherit WRISTS;

void create()
{
    set_name(HIC "瑪瑙手鐲" NOR, ({"bracelet onyx","bracelet"}) );
     set_weight(50);
     if ( clonep() )
              set_default_object(__FILE__);
     else {
            set("long", "一個由瑪瑙作成的美麗手鐲。\n"
            "再仔細玩看，似乎有其它作用 (info bracelet)。\n");
            set("unit", "串");
            set("value", 5000);
            set("no_drop", 1);
            set("armor_prop/armor",2);
            set("armor_prop/dodge", 2);
            set("armor_prop/spells", 2);
            set("wear_msg", "$N把$n帶在手上。\n");
     }
     setup();
}

void init()
{
        if( this_player()==environment() )
            add_action("do_info","info");
            add_action("do_pray","pray");
}

int do_info(string arg)
{
        if( !arg ) return notify_fail("你想知道什麼? \n");
        write("使用 (pray start) ，它會傳送你回起點。\n");
         return 1;
}

int do_pray(string arg)
{
      string name;
       name = (string)this_player()->query("name");

         if( !arg || arg!="start" ) return notify_fail("你要祈求什麼? \n");
         {
         message_vision("$N雙手合掌，虔誠的祈禱。\n"
             "手上的鐲子嗡嗡作響。 突然一陣煙霧.... \n",this_player() );
         this_player()->receive_damage("sen",50);
         tell_room(environment(this_player()),
               name+"的身影消失在空氣中。\n",this_player() );
         tell_room("/d/snow/inn",
              name+"的身影出現在一陣煙霧之中。\n",this_player() );
         this_player()->move("/d/snow/temple");
          }
          return 1;
}
