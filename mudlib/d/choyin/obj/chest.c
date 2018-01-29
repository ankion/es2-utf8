// chest.c

inherit ITEM;

void create()
{
	set_name("桃木箱", ({ "peach chest", "chest" }) );
	set_weight(1400);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "個");
		set("long", "一個刻工相剛精細的桃木箱，也許\是用來裝首飾用的。\n");
		set("value", 300);
		set("material", "wood");
	}
}
