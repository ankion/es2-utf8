// keeper.c

inherit ITEM;

void create()
{
	set_name("功\德箱", ({ "denotation box", "box" }) );
	set("unit", "個");
	set("long",
		"這是寺廟接受善男信女捐獻香油錢的功\德箱，你可以把想捐的錢\n"
		"放進去。\n");
	set("value", 1);
	set("no_get", 1);
	set_max_encumbrance(10000);
}

void insert_object(object ob)
{
	int val;
	object who;
	
	if( !who = this_player() ) return;

	if( !val = ob->value() ) return;

	if( val > 100 ) {
		if( (who->query("bellicosity") > 0)
		&&	(random(val/10) > (int)who->query("kar")) )
			who->add("bellicosity", - (random((int)who->query("kar")) + val/1000) );
	}
	seteuid(getuid());
	destruct(ob);
}
