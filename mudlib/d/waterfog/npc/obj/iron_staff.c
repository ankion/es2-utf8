// iron_staff.c

#include <weapon.h>

inherit STAFF;

void create()
{
	set_name("黑鐵杖", ({ "iron staff", "staff" }) );
	set_weight(70000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "條");
		set("long", "這條黑鐵杖光看就知道非常沈重，拿在手裏才知道比想像中更重。\n");
		set("value", 2800);
		set("material", "iron");
		set("wield_msg", "$N拿出一條黑黝黝的$n握在手中。\n");
		set("unwield_msg", "$N放下手中的$n。\n");
	}

	init_staff(54);
	setup();
}
