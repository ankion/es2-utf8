// coin.c

inherit MONEY;

void create()
{
	set_name("錢", ({"coin", "coins", "coin_money" }));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("money_id", "coin");
		set("long", "這是流通中單位最小的貨幣，約要一百文錢才值得一兩銀子。\n");
		set("unit", "些");
		set("base_value", 1);
		set("base_unit", "文");
		set("base_weight", 1);
	}
	set_amount(1);
}

