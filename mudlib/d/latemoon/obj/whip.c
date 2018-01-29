// echowhip.c

#include <weapon.h>

inherit WHIP;

void create()
{
    set_name( "長鞭", ({ "whip" }) );
    set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "條");
        set("value", 500);
		set("material", "leather");
		set("rigidity", 70);
		set("wield_msg", "$N從腰間解下一條$n握在手中。\n");
		set("unwield_msg", "$N將手中的$n纏回腰間。\n");
	}
    init_whip(10);
	setup();
}
