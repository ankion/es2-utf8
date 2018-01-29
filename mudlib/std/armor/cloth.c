// cloth.c

#include <armor.h>

inherit EQUIP;

void setup()
{
	if( clonep(this_object()) ) return;

	set("armor_type", TYPE_CLOTH);
	if( !query("armor_apply/dodge")
	&&	weight() > 3000 )
		set("armor_prop/dodge", - weight() / 3000 );
}

void init()
{
	add_action("do_tear", "tear");
}

int do_tear(string str)
{
	object ob;

	if( !id(str) ) return 0;

	if( (string)query("material") != "cloth" )
		return notify_fail("你只能撕布料的衣服。\n");

	if( (int)query("teared_count") >= 4 )
		return notify_fail( name() + "的袖口，下□已經沒有多餘的布可撕了。\n");

	message_vision("$N從" + name() + "撕下一條布條。\n", this_player() );
	add("teared_count", 1);
	ob = new("/obj/bandage");
	ob->set_name("從" + name() + "撕下的布條", ({ "cloth piece", "piece", "cloth" }) );
	if( !ob->move(this_player()) )
		ob->move(environment(this_player()));
	return 1;
}
