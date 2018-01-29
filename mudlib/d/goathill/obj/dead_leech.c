// dead_leech.c

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("死巖蛭", ({ "dead leech", "leech" }) );
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一條死得硬梆梆的巖蛭，要不是灰撲撲的顏色，看起來倒是有些像是臘腸。\n");
		set("unit", "只");
		set("value", 0);
		set("food_remaining", 3);
		set("eat_func", (: eat_tonic :) );
		set("tonic", ([ "force": 1, "max_mana": 60 ]) );
		set("food_supply", 70);
	}
	call_out("decay", 240);
}

static void decay()
{
	say("死巖蛭發出一股難聞的惡臭，爛掉了 ... \n");
	destruct(this_object());
}
