#include <ansi.h>
#include <weapon.h>

inherit WHIP;

void create()
{
        set_name( "蛇鱗皮鞭", ({ "snakewhip" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "條");
                set("value", 500);
                set("material", "skin");
                set("rigidity", 100);
        }
        init_whip(15);

        set("wield_msg", "$N從腰間摸出一條$n握在手中。\n");
        set("unwield_msg", "$N將手中的$n束在腰間。\n");
        setup();
}

