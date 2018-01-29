// throwing_knife.c

#include <weapon.h>

inherit THROWING;

void create()
{
	set_name("飛刀", ({ "throwing knife", "knife" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "些");
		set("base_unit", "把");
		set("base_weight", 300);
		set("base_value", 80);
		set("material", "iron");
		set("long",	"飛刀是一種十分輕、銳利的匕首，用來當作暗器使用。\n");
	}
	set_amount(100);
	init_throwing(20);
	setup();
}
