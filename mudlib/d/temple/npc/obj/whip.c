#include <ansi.h>
#include <weapon.h>

inherit WHIP;

void create()

{
     set_name("拂塵", ({"whip"}) );
     set_weight(1000);
     if( clonep() )
             set_default_object(__FILE__);
     else {
     set("unit", "柄");
     set("long", "一柄以藤木爲柄, 馬尾爲絲的拂塵\n");
     set("value", 100);
     set("martial", "wood");
     set("wield_msg", "$N從背後的腰帶抽出一柄$n握在手中。\n");
     set("unwield_msg", "$N將手中的$n放下斜插在背後的腰帶上。\n");
     }
     init_whip(10);
    
     setup();
}
