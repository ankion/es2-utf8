#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
     set_name(HIW "白鳳丸" NOR ,({"white pill","pill" }));
	set("long",
   "這是一顆純白亮麗的丸子，聞了聞有一種上等藥材的味道。\n");
	set("unit", "顆");
	set("base_unit", "顆");
	set("base_weight", 200);
	set_amount(1);
}

void init()
{
	if( this_player()==environment() )
		add_action("do_eat", "eat");
}

int do_eat(string arg)
{
    if( !arg || arg != "pill")  return notify_fail("你要吃甚麼呢? \n");

	message_vision(
	   "$N拿出一顆大丸子，一口給吞了下去。\n"

	"只見$N全身冒出一陣白煙，整個人看起來非常有精神! \n",this_player());
    this_player()->receive_heal("gin", 100);
	this_player()->receive_heal("kee", 300);
	this_player()->receive_heal("sen",100);

	add_amount(-1);
	return 1;
}
