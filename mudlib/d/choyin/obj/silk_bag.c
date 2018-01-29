// silk_bag.c

inherit ITEM;

void create()
{
	set_name("紫羅鴛鴦荷包", ({ "silk bag", "bag", "###silk bag###" }));
	set_weight(200);
	set_max_encumbrance(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "個");
		set("long", "一個繡工十分精細的紫色絲綢荷包，上面繡著一對鴛鴦。\n");
		set("value", 1200);
		set("material", "silk");
	}
}
