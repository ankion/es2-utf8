#include <ansi.h>
#include <armor.h>
inherit WAIST;

void create()
{
       set_name( "綿裙" , ({ "skirt" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
               set("value", 700);
                set("material", "cloth");
                set("armor_prop/armor",2);
        set("wear_msg", "$N將$n拿出系在腰上。\n");
        }
        setup();
}
int wear()
{
     if ((string)this_player()->query("gender") !="女性")
           return notify_fail("只有女生纔可穿哦!你變態呀! \n");
     else {
           ::wear();
          }
     return 1;

}
