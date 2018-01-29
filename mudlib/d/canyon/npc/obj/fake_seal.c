//seal.c

inherit ITEM;

void create()
{
    set_name( "印鑑" ,({ "seal" }) );
	set("long", "上面刻著鎮國大將軍。\n");
	set("unit", "顆");
	set("base_weight", 300);
	set("value", 3000);
	
	set("no_sell", 1);
}


