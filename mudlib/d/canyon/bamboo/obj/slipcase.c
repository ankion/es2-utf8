// slipcase.c

inherit ITEM;

void create()
{
	object obj;
	set_name("書匣", ({ "slipcase" }) );
	set_weight(4000);
    set_max_encumbrance(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        set("unit", "個");
        set("long", "這是一個銅製的書匣，可以用來裝一些書。\n");
		set("value", 1);
	}
	obj=new(__DIR__"parry_book");
	obj->move(this_object());
}

int is_container() { return 1; }
