// silver.c

inherit MONEY;

void create()
{
	set_name("銀子", ({"silver", "ingot", "silver_money"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("money_id", "silver");
		set("long", "白花花的銀子，人見人愛的銀子。\n");
		set("unit", "些");
		set("base_value", 100);
		set("base_unit", "兩");
		set("base_weight", 37);
	}
	set_amount(1);
}

