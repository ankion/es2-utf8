// rope.c

#include <ansi.h>
#include <weapon.h>

inherit WHIP;

void create()
{
        set_name( "麻繩", ({ "rope" }) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "條");
                set("value", 10);
                set("material", "cloth");
        }
	init_whip(1);

        set("wield_msg", "$N從腰間摸出一條$n握在手中。\n");
        set("unwield_msg", "$N將手中的$n束在腰間。\n");

	setup();
}

