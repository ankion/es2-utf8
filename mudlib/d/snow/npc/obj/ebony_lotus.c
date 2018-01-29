// ebony_lotus.c

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("烏雪蓮", ({ "ebony lotus", "lotus" }) );
	set_weight(90);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",
			"這是一種生長在高山冰雪之中的珍貴藥材，據說對修煉內功\的\n"
			"武林人士頗有幫助。\n");
		set("unit", "塊");
		set("value", 30000);
		set("food_remaining", 1);
		set("eat_func", (: eat_tonic :) );
		set("tonic", ([ "force": 60, "max_force": 2000 ]) );
		set("food_supply", 100);
	}
}
