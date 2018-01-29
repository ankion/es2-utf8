//seal.c

#include <ansi.h>

inherit ITEM;

void create()
{
    set_name("[1;33m印鑑[0m",({ "seal" }) );
	set("long", "泛著黃光，上面刻著鎮國大將軍。\n");
	set("unit", "顆");
	set("base_weight", 200);

	set("no_sell", 1);
}


