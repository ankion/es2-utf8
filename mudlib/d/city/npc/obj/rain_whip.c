// rainwhip.c
#include <ansi.h>
#include <weapon.h>
inherit WHIP;

void create()
{
        set_name( HIM "煙雨鞭" NOR, ({ "rain whip", "whip" }) );
        set_weight(17000);
        if( clonep() )
                set_default_object(__FILE__);
        else {

	        set("unit", "條");
	        set("value", 20000);
       		set("material", "leather");
	}

	init_whip(28);

        set("wield_msg", "$N從腰間解下一條$n握在手中。\n");
        set("unwield_msg", "$N將手中的$n纏回腰間。\n");

        setup();
}

