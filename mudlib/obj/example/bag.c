// bag.c

inherit ITEM;

void create()
{
	set_name("布袋", ({ "bag" }) );
	set_weight(500);
	set_max_encumbrance(8000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "口");
		set("long", "這是一口尋常的布袋，可以用來裝一些雜物。\n");
		set("value", 1);
	}
}

int is_container() { return 1; }
