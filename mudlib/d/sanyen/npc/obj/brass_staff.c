// brass_staff.c

#include <weapon.h>

inherit STAFF;

void create()
{
	set_name("黃銅禪杖", ({ "brass staff", "staff" }) );
	set_weight(20000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "條");
		set("long", "一條又粗又長，非常沈重的黃銅禪杖，上面鑲著六個銅環。\n");
		set("value", 1200);
		set("material", "brass");
		set("wield_msg", "$N拿出一根金光燦然的$n握在手中。\n");
		set("unwield_msg", "$N放下手中的$n。\n");
	}

	init_staff(34);
	setup();
}
