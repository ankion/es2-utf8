// vendor.c

#include <dbase.h>

int buy_object(object me, string what)
{
	string ob;

	if( stringp(ob = query("vendor_goods/" + what)) )
		return ob->query("value");
	else
		return 0;
}

void compelete_trade(object me, string what)
{
	string ob_file;
	object ob;

	if( stringp(ob_file = query("vendor_goods/" + what)) ) {
		ob = new(ob_file);
		ob->move(me);
		message_vision("$N向$n買下一" + ob->query("unit") + ob->query("name") + "。\n",
			me, this_object() );
	}
}

string price_string(int v)
{
	if( v%10000 == 0 )
		return (v/10000) + "兩黃金";
	if( v%100 == 0 )
		return (v/100) + "兩銀子";
	return v + "文錢";
}

string get_vendor_list(string arg)
{
	mapping goods;
	string list, *id;
	int i;

	if( !mapp(goods = query("vendor_goods")) ) return 0;
	if( arg && !this_object()->id(arg) ) return 0;
	id = keys(goods);
	list = "你可以購買下列這些東西：\n";
	for(i=0; i<sizeof(id); i++)
		list += sprintf("%s(%s)：%10s\n",
            goods[id[i]]->name(),
			id[i],
			price_string(goods[id[i]]->query("value")) );
  return list;
}

int do_vendor_list(string arg)
{
    string list;
    list = get_vendor_list(arg);
    if(list && stringp(list)) write(list);
    return 1;
}
