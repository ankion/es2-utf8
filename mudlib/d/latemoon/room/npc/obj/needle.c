#include <weapon.h>

inherit THROWING;

void create()
{
    set_name( "花針" , ({"needle" }) );
     if ( clonep() )
              set_default_object(__FILE__);
     else {
             set("long", "一種鐵做成的繡花針\n");
          set("unit", "些");
          set("base_unit", "根");
          set("base_weight", 30);
          set("base_value", 100);
          set("material", "iron");
     }
     set_amount(1);
     init_throwing(10);
     setup();
}
